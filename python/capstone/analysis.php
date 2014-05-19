<?php
function get_conn_and_connect()
{
    $con = mysql_connect("localhost","root","root");
    if (!$con)
      {
      	echo("I can't get a connection");
      }

    if (!mysql_select_db("Results", $con))
      {
      	echo("problem with connecting to db");
      }

    return $con;
}

function add($table, $fields, $values)
{
    if(sizeof($fields) != sizeof($values))
    {
	echo"error in add field and value mismatch.";
	return 0;
    }
    $con = get_conn_and_connect();
    $sql="";
    $sql2="";
    for ($i=0; $i<sizeof($fields); $i++)
    {
	$sql.="$fields[$i],";
        $val =  mysql_real_escape_string($values[$i]);
	$sql2.="'$val',";
    }
    $sql = "INSERT INTO $table(".substr($sql,0,-1).")VALUES(".substr($sql2,0,-1).")";
    $result = mysql_query($sql);
    
    close_conn($con);
}

function get($table, $fields, $values)
{
    if(sizeof($fields) != sizeof($values))
    {
	echo"error in add field and value mismatch.";
	return 0;
    }
    $sql = "";
    for ($i=0; $i<sizeof($fields); $i++)
    {
	$sql.= ("$fields[$i]='".mysql_real_escape_string($values[$i])."' AND ");
    }
    $sql = "SELECT * FROM $table WHERE ".substr($sql,0,-5);
    $con = get_conn_and_connect();
    $query = mysql_query($sql, $con);
    $row = mysql_fetch_array($query);
    //echo "row: ".$row;
    if ($row == false) 
    {
        close_conn($con);
        return false;
    }
    close_conn($con);
    return $row;
}

function get_result($author, $algorithm)
{
    $sql = "SELECT * FROM Result WHERE algorithm = '".$algorithm."' and y_author = '".$author."' order by ncd";   
    $con = get_conn_and_connect();
    $query = mysql_query($sql, $con);
    $rows = array();
    $i = 0;

    while ($row = mysql_fetch_assoc($query))
    {
		$rows[$i] = $row;
		$i++;
    }
    if (sizeof($rows) == 0) 
    {
        close_conn($con);
        return false;
    }
    close_conn($con);
    return $rows;
}

function get_a_compression_sz($book_name)
{
    //echo "book: ".$book_name."<br>";
    $fields = array("book_name");
    $values = array($book_name);
    $arr = get("Arithmetic_Analysis", $fields, $values);
    //echo "id: ".$arr[0]."name: ".$arr[1]."complete: ".$arr[2]."rate: ".$arr[3]."avg len: ".$arr[4]."ratio: ".$arr[5]."ratio%: ".$arr[6]."sz: ".$arr[7]."author: ".$arr[8];
    return (float)$arr[7];
}

function get_h_compression_sz($book_name, $complete)
{
    $fields = array("book_name", "complete");
    $values = array($book_name, $complete);
    $arr = get("Huffman_Analysis", $fields, $values);
    return (float)$arr[7];
}

function close_conn($con) 
{
    mysql_close($con);
}

function add_huffman_analysis($book_name, $complete, $rate, $avg_codeword_length, $ratio, $ratio_percentage, $compression_sz_bytes, $author, $entropy, $metric_entropy, $book_group, $num_bits)
{
    $fields = array("book_name", "complete", "rate", "avg_codeword_length", "ratio", "ratio_percentage", "compression_sz_bytes", "author", "entropy", "metric_entropy", "book_group", "num_bits");
    $values = array($book_name, $complete, $rate, $avg_codeword_length, $ratio, $ratio_percentage, $compression_sz_bytes, $author, $entropy, $metric_entropy, $book_group, $num_bits);
    add("Huffman_Analysis", $fields, $values);
}

function add_arithmetic_analysis($book_name, $complete, $rate, $avg_length, $ratio, $ratio_percentage, $compression_sz_bytes, $author,  $book_group)
{
    $fields = array("book_name", "complete", "rate", "avg_length", "ratio", "ratio_percentage", "compression_sz_bytes", "author", "book_group");
    $values = array($book_name, $complete, $rate, $avg_length, $ratio, $ratio_percentage, $compression_sz_bytes, $author, $book_group);
    add("Arithmetic_Analysis", $fields, $values);
}

function store_result($name1, $name2, $author1, $author2, $ncd, $same_author, $result, $algorithm)
{
    $fields = array("book_x", "book_y", "x_author", "y_author", "ncd", "same_author", "result", "algorithm");
    $values = array($name1, $name2, $author1, $author2, $ncd, $same_author, $result, $algorithm);
    add("Result", $fields, $values);
}

function store_ncd($name1, $name2, $author1, $author2, $same_author, $algorithm)
{
    if($algorithm == "a")
    {
        $c_x = get_a_compression_sz($name1);
        $c_y = get_a_compression_sz($name2);
        $c_xy = get_a_compression_sz($name1."_".$name2, $algorithm);
    }
    else if($algorithm == "h")
    {
        $c_x = get_h_compression_sz($name1, "no");
        $c_y = get_h_compression_sz($name2, "no");
        $c_xy = get_h_compression_sz($name1."_".$name2, "no");
    }
    else
    {
        $c_x = get_h_compression_sz($name1, "yes");
        $c_y = get_h_compression_sz($name2, "yes");
        $c_xy = get_h_compression_sz($name1."_".$name2, "yes");
    }
    //compute ncd 
    if($c_x < $c_y)
    {
        $ncd = (float)($c_xy - $c_x) / $c_y;
    }
    else
    {
        $ncd = (float)($c_xy - $c_y) / $c_x;
    }
    /*echo "cx: ".$c_x."<br>";
    echo "cy: ".$c_y."<br>";
    echo "cxy: ".$c_xy."<br>";
    echo "ncd: ".$ncd."<br>";
    echo "same: ".$same_author."<br>";
    echo "name1: ".$name1."<br>";
    echo "name2: ".$name2."<br>";*/
    if($same_author == "y")
    {
        switch ($ncd) 
        {
        case $ncd < 0.2:
            $result = 1;
            break;
        case $ncd < 0.4:
            $result = 2;
            break;
        case $ncd < 0.6:
            $result = 3;
            break;
        case $ncd < 0.8:
            $result = 4;
            break;
        default:
            $result = 5;
            break;
        }
    }
    else
    {
        switch ($ncd) 
        {
        case $ncd < 0.2:
            $result = 5;
            break;
        case $ncd < 0.4:
            $result = 4;
            break;
        case $ncd < 0.6:
            $result = 3;
            break;
        case $ncd < 0.8:
            $result = 2;
            break;
        default:
            $result = 1;
            break;
        }
    }
    //echo "result: ".$result."<br>";
    store_result($name1, $name2, $author1, $author2, $ncd, $same_author, $result, $algorithm);
   
}

function read_file($fname)
{
	//returns an array of the lines of the file
	$arr = array();
	$fp = fopen($fname, 'r');
	while ( ($current_line = fgets($fp)) !== false )
	{
		$arr[] = $current_line;
	}
	fclose($fp);
	return $arr;
}

function store_arithmetic_file($name, $fname, $ext, $book_group, $author)
{
    //open file
    $fname = "../books/".$fname.$ext;
    $arr = read_file($fname);
    $complete = "no";
    $rate = $arr[1];
    $avg_length = $arr[0];
    $ratio = $arr[6];
    $ratio_percentage = $arr[4];
    $compression_sz_bytes = $arr[3];

    //echo $name."  ".$complete."  ".$rate."  ".$avg_length."  ".$ratio."  ".$ratio_percentage."  ".$compression_sz_bytes."  ".$author."  ".$book_group."<br>";
    add_arithmetic_analysis($name, $complete, $rate, $avg_length, $ratio, $ratio_percentage, $compression_sz_bytes, $author, $book_group);
}

function store_huffman_file($name, $fname, $ext, $complete, $book_group, $author)
{
    //open file
    $fname = "../books/".$fname.$ext;
    //echo $fname;
    $arr = read_file($fname);
    $entropy = (float)$arr[0];
    //echo $arr[0]."  and  ".$arr[1];
    $metric_entropy = (float)$arr[1];
    $num_bits = intval($arr[2]);
    $rate = $arr[4];
    $avg_codeword_length = $arr[3];
    $ratio = $arr[9];
    $ratio_percentage = $arr[7];
    $compression_sz_bytes = $arr[6];

    //echo $name."  ".$complete."  ".$rate."  ".$avg_codeword_length."  ".$ratio."  ".$ratio_percentage."  ".$compression_sz_bytes."  ".$author."  ".$entropy."  ".$metric_entropy."  ".$book_group."  ".$num_bits."<br>";
    add_huffman_analysis($name, $complete, $rate, $avg_codeword_length, $ratio, $ratio_percentage, $compression_sz_bytes, $author, $entropy, $metric_entropy, $book_group, $num_bits);
    //////////////////////////
}

function determine_results($arr_authors, $algorithm)
{
    echo "<table border='1' cellpadding='10'><tr><th>Actual Author</th><th>Author with lowest ncd</th><th>Author with lowest 2 ncd</th><th>Author with lowest avg ncd</th><th>Avg lowest ncd</th><th>Index of book 1 in lowest ncds</th><th>Index of book 2 in lowest ncds</th><th>Index of book 3 in lowest ncds</th><th>Index of book 4 in lowest ncds</th></tr>";
    $max = sizeof($arr_authors);
    for ($i=1; $i<$max; $i++)
    {
        $results = get_result($arr_authors[$i], $algorithm);
        $author_count = array_fill(0, 21, 0);
        $a_ncd_count = array_fill(0, 21, 0);
        $a_ncd_count[0] = 99;
        $maxr = sizeof($results);
        $count = 0;
        $f_author = "null";
        $s_author = "null";

        for ($j=0; $j<$maxr; $j++)
        {//book , author, s_author, pos1, pos2, pos3, pos4, auth_l_ncd, algorithm
            $index = array_search($results[$j]["x_author"], $arr_authors);
            $a_ncd_count[$index] += $results[$j]["ncd"];
            if ($f_author == "null")
            {
                $author_count[$index] += 1;
                if ($author_count[$index] == 2)
                {
                    $f_author = $results[$j]["x_author"];
                }
            }
            
            if($results[$j]["same_author"] == 'y')
            {
                $count += 1;
                if ($count == 1)
                {
                    $pos1 = $j+1;
                }
                if ($count == 2)
                {
                    $pos2 = $j+1;
                }
                if ($count == 3)
                {
                    $pos3 = $j+1;
                }
                if ($count == 4)
                {
                    $pos4 = $j+1;
                }
            }  
        }
    ///check which ncd is lowest
        $low = min($a_ncd_count);
        $idx = array_search($low, $a_ncd_count);
        $low_a = $arr_authors[$idx];
        //echo "  pos1  ".$pos1."      pos2  ".$pos2."      pos3  ".$pos3."        pos4  ".$pos4."  actual  ".$arr_authors[$i]."  f_author  ".$f_author."  lowest ncd author  ".$low_a."  val:  ".$low/4.0."<br>";
        $s_author = $results[0]["x_author"];
        echo "<tr><td>".$arr_authors[$i]."</td><td>".$s_author."</td><td>".$f_author."</td><td>".$low_a."</td><td>".$low/4.0."</td><td>".$pos1."</td><td>".$pos2."</td><td>".$pos3."</td><td>".$pos4."</td></tr>";

    }
    echo "</table>";
}

$arr_x = array("PepperAndSaltOrSeasoningForYoungFolk17", "LoveAndOtherStories1", "AJollyFellowship3", "Alice'sAdventuresInWonderland4", "ARoomWithAView5", "ASonOfTheImmortals6", "ASportsman'sSketches7", "AStrangeStory8", "ATaleOfTwoCities9", "ATangledTale4", "BrotherAgainstBrother2", "CarnacsFolly10", "ChristmasEveAndChristmasDay11", "CongressionalGovernment12", "DavidCopperfield9",  "DonovanPashaAndSomePeopleOfEgypt10", "DorothyAndTheWizardInOz13", "EnochArden14", "FiveChildrenAndIt15", "GreatExpectations9", "HouseOfMirth16", "HowardPyle'sBookOfPirates17",  "InOurFirstYearOfTheWar12", "AMan'sWoman19", "ItsRiseAndFall8", "MarkTwain'sSpeeches18", "MenofIron17", "MichelAndAngele10", "OliverTwist9", "OnTheBlockade2", "MoranOfTheLadyLetty19", "OzmaOfOz13", "PaulClifford8",  "Round-aboutRamblesInLandsOfFactAndFancy3", "Rudin7", "SelectionsFromWordsworthAndTennyson14", "SketchesNewAndOld18", "SkylarkThree20", "SpacehoundsOfIpc20", "StateOfTheUnionAddressesOfWoodrowWilson12", "StoriesOfInvention11", "Summer16", "SylvieAndBruno4", "SymbolicLogic4", "TakenByTheEnemy2", "TheAdventuresOfTomSawyer18", "TheAgeOfInnocence16", "TheBookOfDragons15", "TheBrickMoon11", "TheCelestialOmnibusAndOtherStories5", "TheDuelAndOtherStories1", "TheChorusGirlAndOtherStories1", "TheCustomOfTheCountry16", "TheDiaryOfASuperfluousManAndOtherStories7", "TheEarlyPoemsOfAlfredLordTennyson14", "TheEmeraldCityOfOz13", "TheEnchantedCastle15", "TheGreatStoneOfSardis3", "TheLadyWithTheDogAndOtherStories1", "TheLastDaysOfPompeii8", "TheLongestJourney5", "TheManWithoutACountryAndOtherTales11", "TheMerryAdventuresOfRobinHood17", "TheNewFreedom12", "TheOctopus19", "ThePillarOfLight6", "ThePit19", "ThePrinceAndThePauper18", "TheRedYear6", "TheRightOfWay10", "TheSkylarkOfSpace20", "TheSquirrelInn3", "TheStoryOfTheTreasureSeekers15", "TheSuppressedPoemsOfAlfredLordTennyson14", "TheTermsOfSurrender6", "TheTorrentsOfSpring7", "TheWonderfulWizardOfOz13", "TheYachtClub2", "Triplanetary20", "WhereAngelsFearToTread5");

$arr_y = array("TheWifeAndOtherStories1", "AdventuresOfHuckleberryFinn18", "AmericanFairyTales13", "BuccaneersAndPiratesOfOurCoasts3", "Cumner&SouthSeaFolk10", "EthanFrome16", "HowardsEnd5", "IdyllsOfTheKing14", "McTeague19", "OnTheEve7", "PresidentWilson'sAddresses12", "StolenTreasure17", "TheComingRace8", "TheGalaxyPrimes20", "TheLifeOfChristopherColumbus11", "TheRailwayChildren15", "AChristmasCarol9", "TheWingsOfTheMorning6", "ThroughTheLooking-Glass4", "AcrossIndia2");

$arr_authors = array("none", "Anton Chekhov",  "Oliver Optic",  "Frank Richard Stockton", "Lewis Carroll", "E. M. Forster", "Louis Tracy", "Ivan Turgenev", "Edward Bulwer Lytton", "Charles Dickens", "Gilbert Parker", "Edward Everett Hale", "Woodrow Wilson", "L. Frank Baum", "Alfred Tennyson", "Edith Nesbit", "Edith Wharton", "Howard Pyle", "Mark Twain", "Frank Norris", "E.E. Smith");
/*
$max = sizeof($arr_x);
for ($i=0; $i<$max; $i++)
{
    $d = substr($arr_x[$i], strlen($arr_x[$i])-2, 2);
    if(is_numeric($d))
    {
        $name = substr($arr_x[$i], 0, -2);
        $author = $arr_authors[intval($d)];
    }
    else
    {
        $d = substr($arr_x[$i], strlen($arr_x[$i])-1, 1);
        $name = substr($arr_x[$i], 0, -1);
        $author = $arr_authors[intval($d)];
    }
    store_huffman_file($name, $arr_x[$i], "_h_k.txt", "no", "k", $author);
 
    store_huffman_file($name, $arr_x[$i], "_B_k.txt", "yes", "k", $author);
    
    store_arithmetic_file($name, $arr_x[$i], "_a_k.txt", "k", $author);
}

//////////////////////////////////////////
$max = sizeof($arr_y);
for ($i=0; $i<$max; $i++)
{
    $d = substr($arr_y[$i], strlen($arr_y[$i])-2, 2);
    if(is_numeric($d))
    {
        $name = substr($arr_y[$i], 0, -2);
        $author = $arr_authors[intval($d)];
    }
    else
    {
        $d = substr($arr_y[$i], strlen($arr_y[$i])-1, 1);
        $name = substr($arr_y[$i], 0, -1);
        $author = $arr_authors[intval($d)];
    }
    store_huffman_file($name, $arr_y[$i], "_h_u.txt", "no", "u", $author);
 
    store_huffman_file($name, $arr_y[$i], "_B_k.txt", "yes", "k", $author);
    
    store_arithmetic_file($name, $arr_y[$i], "_a_u.txt", "u", $author);    
}
///////////////////////////////////////////////////

$maxx = sizeof($arr_x);
$maxy = sizeof($arr_y);
for ($i=0; $i<$maxx; $i++)
{
    for ($j=0; $j<$maxy; $j++)
    {
        $d1 = substr($arr_x[$i], strlen($arr_x[$i])-2, 2);
        if(is_numeric($d1))
        {
            $name1 = substr($arr_x[$i], 0, -2);
            $author1 = $arr_authors[intval($d1)];
        }
        else
        {
            $d1 = substr($arr_x[$i], strlen($arr_x[$i])-1, 1);
            $name1 = substr($arr_x[$i], 0, -1);
            $author1 = $arr_authors[intval($d1)];
        }

        $d2 = substr($arr_y[$j], strlen($arr_y[$j])-2, 2);
        if(is_numeric($d2))
        {
            $name2 = substr($arr_y[$j], 0, -2);
            $author2 = $arr_authors[intval($d2)];
        }
        else
        {
            $d2 = substr($arr_y[$j], strlen($arr_y[$j])-1, 1);
            $name2 = substr($arr_y[$j], 0, -1);
            $author2 = $arr_authors[intval($d2)];
        }
        store_huffman_file($name1."_".$name2, $arr_x[$i]."_".$arr_y[$j], "_h_c.txt", "no", "c", $author1."_".$author2);
     
        store_huffman_file($name1."_".$name2, $arr_x[$i]."_".$arr_y[$j], "_B_k.txt", "yes", "k", $author1."_".$author2);
        
        store_arithmetic_file($name1."_".$name2, $arr_x[$i]."_".$arr_y[$j], "_a_c.txt", "c", $author1."_".$author2);  

        if ($author1 == $author2)
        {
            $same_author = "y";
        }
        else
        {
            $same_author = "n";
        }

        store_ncd($name1, $name2, $author1, $author2, $same_author, "a");
	    store_ncd($name1, $name2, $author1, $author2, $same_author, "h");
        store_ncd($name1, $name2, $author1, $author2, $same_author, "B");	    
    }
}
*/
echo "<br>huffman a<br>";
determine_results($arr_authors, "a");
echo "<br>huffman h<br>";
determine_results($arr_authors, "h");
echo "<br>huffman B<br>";
determine_results($arr_authors, "B");

echo "all done whoop!";
/*
1.for loop through experimental group adding to book and analysis
2.nested for loop
  A. Outer loop through control group adding to book and analysis
  B. Inner loop through concatinated group adding to book and analysis and compute ncd for each
3.compare
*/

php?>
