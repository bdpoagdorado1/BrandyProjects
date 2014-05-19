// Name: Brandy Poag
// File: testString.cpp

#include <iostream>
#include "String.h"

int main()
{
	String s1("abc");
	std::cout << "s1 " << s1 << '\n';
	std::cout << s1.size() << '\n';
	String s11("abcjhlkdjgf;ljks;ljk;lgjds;l");
	std::cout << "s11 " << s11 << '\n';
	std::cout << s11.size() << '\n';
	String s12("456456444444");
	std::cout << "s12 " << s12 << '\n';
	std::cout << s12.size() << '\n';
	String s13("");
	std::cout << "s13 " << s13 << '\n';
	std::cout << s13.size() << '\n';
	String s14("a");
	std::cout << "s14 " << s14 << '\n';
	std::cout << s14.size() << '\n';
	String s15("Hello world");
	std::cout << "s15 " << s15 << '\n';
	std::cout << s15.size() << '\n';
	String s16("The quick brown fox jumps over the lazy dog. 0123456789");
	std::cout << "s16 " << s16 << '\n';
	std::cout << s16.size() << '\n';
	String s2('a');
	std::cout << "s2 " << s2 << '\n';
	std::cout << s2.size() << '\n';
	String s21('4');
	std::cout << "s21 " << s21 << '\n';
	std::cout << s21.size() << '\n';
	String s22('!');
	std::cout << "s22 " << s22 << '\n';
	std::cout << s22.size() << '\n';
	String s23('A');
	std::cout << "s23 " << s23 << '\n';
	std::cout << s23.size() << '\n';
	String s24('0');
	std::cout << "s24 " << s24 << '\n';
	std::cout << s24.size() << '\n';
	String s3;
	std::cout << "s3 " << s3 << '\n';
	String s4;
	std::cin >> s4;
	std::cout << "s4 " << s4 << '\n';
	String s5(s4);
	std::cout << "s5 " << s5 << '\n';
	std::cout << s5.size() << '\n';
	String s51(s3);
	std::cout << "s51 " << s51 << '\n';
	std::cout << s51.size() << '\n';
	String s52(s4);
	std::cout << "s52 " << s52 << '\n';
	std::cout << s52.size() << '\n';
	String s53(s12);
	std::cout << "s53 " << s53 << '\n';
	std::cout << s53.size() << '\n';
	String s54(s16);
	std::cout << "s54 " << s54 << '\n';
	std::cout << s54.size() << '\n';

	String s6("abe");
	std::cout << "s6 " << s6 << '\n';

	std::cout << '"' << s4 << "\" is == to \"" << s5 << "\" " << (s4 == s5) << '\n';
	std::cout << '"' << s4 << "\" is != to \"" << s5 << "\" " << (s4 != s5) << '\n';
	std::cout << '"' << s4 << "\" is > to \"" << s5 << "\" " << (s4 > s5) << '\n';
	std::cout << '"' << s4 << "\" is < to \"" << s5 << "\" " << (s4 < s5) << '\n';
	std::cout << '"' << s4 << "\" is >= to \"" << s5 << "\" " << (s4 >= s5) << '\n';
	std::cout << '"' << s4 << "\" is <= to \"" << s5 << "\" " << (s4 <= s5) << '\n';

	std::cout << '"' << s3 << "\" is == to \"" << s5 << "\" " << (s3 == s5) << '\n';
	std::cout << '"' << s3 << "\" is > to \"" << s5 << "\" " << (s3 > s5) << '\n';
	std::cout << '"' << s3 << "\" is < to \"" << s5 << "\" " << (s3 < s5) << '\n';
	std::cout << '"' << s3 << "\" is >= to \"" << s5 << "\" " << (s3 >= s5) << '\n';
	std::cout << '"' << s3 << "\" is <= to \"" << s5 << "\" " << (s3 <= s5) << '\n';
	std::cout << '"' << s3 << "\" is != to \"" << s5 << "\" " << (s3 != s5) << '\n';

	std::cout << '"' << s1 << "\" is == to \"" << s6 << "\" " << (s1 == s6) << '\n';
	std::cout << '"' << s1 << "\" is != to \"" << s6 << "\" " << (s1 != s6) << '\n';
	std::cout << '"' << s1 << "\" is >= to \"" << s6 << "\" " << (s1 >= s6) << '\n';
	std::cout << '"' << s1 << "\" is > to \"" << s6 << "\" " << (s1 > s6) << '\n';
	std::cout << '"' << s1 << "\" is <= to \"" << s6 << "\" " << (s1 <= s6) << '\n';
	std::cout << '"' << s1 << "\" is < to \"" << s6 << "\" " << (s1 < s6) << '\n';

	std::cout << '"' << s11 << "\" is == to \"" << s6 << "\" " << (s11 == s6) << '\n';
	std::cout << '"' << s11 << "\" is != to \"" << s6 << "\" " << (s11 != s6) << '\n';
	std::cout << '"' << s11 << "\" is >= to \"" << s6 << "\" " << (s11 >= s6) << '\n';
	std::cout << '"' << s11 << "\" is > to \"" << s6 << "\" " << (s11 > s6) << '\n';
	std::cout << '"' << s11 << "\" is <= to \"" << s6 << "\" " << (s11 <= s6) << '\n';
	std::cout << '"' << s11 << "\" is < to \"" << s6 << "\" " << (s11 < s6) << '\n';

	std::cout << '"' << s12 << "\" is == to \"" << s16 << "\" " << (s11 == s16) << '\n';
	std::cout << '"' << s12 << "\" is != to \"" << s16 << "\" " << (s11 != s16) << '\n';
	std::cout << '"' << s12 << "\" is >= to \"" << s16 << "\" " << (s11 >= s16) << '\n';
	std::cout << '"' << s12 << "\" is > to \"" << s16 << "\" " << (s11 > s16) << '\n';
	std::cout << '"' << s12 << "\" is <= to \"" << s16 << "\" " << (s11 <= s16) << '\n';
	std::cout << '"' << s12 << "\" is < to \"" << s16 << "\" " << (s11 < s16) << '\n';

	s1 += s16;
	std::cout << "s1 " << s1 << '\n';
	String s71 = s1 + s16;
	std::cout << "s1 " << s1 << '\n';
	std::cout << "s71 " << s71 << '\n';

	s1 += s15;
	std::cout << "s1 " << s1 << '\n';
	String s72 = s1 + s15;
	std::cout << "s1 " << s1 << '\n';
	std::cout << "s7 " << s72 << '\n';

	s1 += s11;
	std::cout << "s1 " << s1 << '\n';
	String s73 = s1 + s11;
	std::cout << "s1 " << s1 << '\n';
	std::cout << "s7 " << s73 << '\n';

	s1 += s12;
	std::cout << "s1 " << s1 << '\n';
	String s74 = s1 + s12;
	std::cout << "s1 " << s1 << '\n';
	std::cout << "s7 " << s74 << '\n';

	s1 += s6;
	std::cout << "s1 " << s1 << '\n';
	String s7 = s1 + s6;
	std::cout << "s1 " << s1 << '\n';
	std::cout << "s7 " << s7 << '\n';

	s7 += 'a';
	std::cout << "s7 " << s7 << '\n';

	s7 += '!';
	std::cout << "s7 " << s7 << '\n';

	s7 += '0';
	std::cout << "s7 " << s7 << '\n';

	s7 += '7';
	std::cout << "s7 " << s7 << '\n';

	s7 += 'H';
	std::cout << "s7 " << s7 << '\n';

	s7 += "wxy";
	std::cout << "s7 " << s7 << '\n';

	s7 += "HHH";
	std::cout << "s7 " << s7 << '\n';

	s7 += "G";
	std::cout << "s7 " << s7 << '\n';

	s7 += "0";
	std::cout << "s7 " << s7 << '\n';

	s7 += "&";
	std::cout << "s7 " << s7 << '\n';

	String s8 = s7 + 'z';
	std::cout << "s7 " << s7 << '\n';
	std::cout << "s8 " << s8 << '\n';

	String s81 = s7 + 'X';
	std::cout << "s7 " << s7 << '\n';
	std::cout << "s81 " << s81 << '\n';

	String s82 = s7 + '0';
	std::cout << "s7 " << s7 << '\n';
	std::cout << "s82 " << s82 << '\n';

	String s83 = s7 + '9';
	std::cout << "s7 " << s7 << '\n';
	std::cout << "s83 " << s83 << '\n';

	String s84 = s7 + '!';
	std::cout << "s7 " << s7 << '\n';
	std::cout << "s84 " << s84 << '\n';

	String s99 = "Me";
	String s9 = s99 + "Brandy";
	std::cout << "s99 " << s99 << '\n';
	std::cout << "s9 " << s9 << '\n';

	String s91 = s99 + "brandy";
	std::cout << "s99 " << s99 << '\n';
	std::cout << "s91 " << s91 << '\n';

	String s92 = s99 + "98";
	std::cout << "s99 " << s99 << '\n';
	std::cout << "s92 " << s92 << '\n';

	String s93 = s99 + "";
	std::cout << "s99 " << s99 << '\n';
	std::cout << "s93 " << s93 << '\n';

	String s94 = s99 + "!";
	std::cout << "s99 " << s99 << '\n';
	std::cout << "s94 " << s94 << '\n';

	String s10 = 'x' + s9;
	std::cout << "s10 " << s10 << '\n';

	String s101 = '@' + s9;
	std::cout << "s101 " << s101 << '\n';

	String s102 = '0' + s9;
	std::cout << "s102 " << s102 << '\n';

	String s103 = '9' + s9;
	std::cout << "s103 " << s103 << '\n';

	String s104 = 'V' + s9;
	std::cout << "s104 " << s104 << '\n';

	String s100('d');
	String s110 = "brandy" + s100;
	std::cout << "s110 " << s110 << '\n';
	std::cout << "s100 " << s100 << '\n';

	String s111 = "**" + s100;
	std::cout << "s111 " << s111 << '\n';
	std::cout << "s100 " << s100 << '\n';

	String s112 = "BrandY" + s100;
	std::cout << "s112 " << s112 << '\n';
	std::cout << "s100 " << s100 << '\n';

	String s113 = " " + s110;
	std::cout << "s113 " << s113 << '\n';
	std::cout << "s100 " << s100 << '\n';

	String s114 = "0" + s100;
	std::cout << "s114 " << s114 << '\n';
	std::cout << "s100 " << s100 << '\n';

	String s120 ("brandypoag");
	String s130 ("dian");
	s120.insert(6, s130);
	std::cout << "s120 " << s120 << '\n';
	String s140 = s120.substr(6);
	std::cout << "s140 " << s140 << '\n';
	String s150 = s120.substr(6, 4);
	std::cout << "s150 " << s150 << '\n';
	s120.insert(6, s130, 1);
	std::cout << "s120 " << s120 << '\n';
	String s160 = s120.substr(6, 1000);
	std::cout << "s160 " << s160 << '\n';
	std::cout << s120.find(s130) << '\n';
	std::cout << s120.find(s160) << '\n';
	std::cout << s120.find("an") << '\n';
	std::cout << s120.find("xan") << '\n';
	std::cout << s120.find('a') << '\n';
	std::cout << s120.find('x') << '\n';
	String s170('a');
	std::cout << s120.rfind(s170) << '\n';
	String s180("oa");
	std::cout << s120.rfind(s180) << '\n';
	std::cout << s120.rfind("ydd") << '\n';
	std::cout << s120.rfind('y') << '\n';
	std::cout << s120.rfind("dd") << '\n';
	const char a56 = 'c';
	std::cout << String(a56) << '\n';
	std::cout << String('d') << '\n';

	String s1201 ("br");
	String s1301 ("dian");
	s1201.insert(1, s1301);
	std::cout << "s1201 " << s1201 << '\n';
	String s1401 = s1201.substr(1);
	std::cout << "s1401 " << s1401 << '\n';
	String s1501 = s1201.substr(1, 4);
	std::cout << "s1501 " << s1501 << '\n';
	s1201.insert(1, s1301, 1);
	std::cout << "s1201 " << s1201 << '\n';
	String s1601 = s1201.substr(1, 1000);
	std::cout << "s1601 " << s1601 << '\n';
	std::cout << s1201.find(s1301) << '\n';
	std::cout << s1201.find(s1601) << '\n';
	std::cout << s1201.find("an") << '\n';
	std::cout << s1201.find("xan") << '\n';
	std::cout << s1201.find('b') << '\n';
	std::cout << s1201.find('r') << '\n';
	String s1701('a');
	std::cout << s1201.rfind(s1701) << '\n';
	String s1801("oa");
	std::cout << s1201.rfind(s180) << '\n';
	std::cout << s1201.rfind("ydd") << '\n';
	std::cout << s1201.rfind('y') << '\n';
	std::cout << s1201.rfind("dd") << '\n';
	const char a561 = '8';
	std::cout << String(a561) << '\n';
	std::cout << String('0') << '\n';

	String s1202 ("poag");
	String s1302 ("an");
	s1202.insert(6, s130);
	std::cout << "s1202 " << s1202 << '\n';
	String s1402 = s1202.substr(6);
	std::cout << "s1402 " << s1402 << '\n';
	String s1502 = s1202.substr(3, 1);
	std::cout << "s1502 " << s1502 << '\n';
	s1202.insert(3, s1302, 1);
	std::cout << "s1202 " << s1202 << '\n';
	String s1602 = s1202.substr(2, 1000);
	std::cout << "s1602 " << s1602 << '\n';
	std::cout << s1202.find(s1302) << '\n';
	std::cout << s1202.find(s1602) << '\n';
	std::cout << s1202.find("an") << '\n';
	std::cout << s1202.find("xan") << '\n';
	std::cout << s1202.find('a') << '\n';
	std::cout << s1202.find('x') << '\n';
	String s1702('a');
	std::cout << s1202.rfind(s1702) << '\n';
	String s1802("oa");
	std::cout << s1202.rfind(s1802) << '\n';
	std::cout << s1202.rfind("ydd") << '\n';
	std::cout << s1202.rfind('y') << '\n';
	std::cout << s1202.rfind("dd") << '\n';
	const char a564 = '!';
	std::cout << String(a564) << '\n';
	std::cout << String('@') << '\n';

	String s1203 ("dianbrandypoag");
	String s1303 ("dian");
	s1203.insert(6, s1303);
	std::cout << "s1203 " << s1203 << '\n';
	String s1403 = s1203.substr(6);
	std::cout << "s1403 " << s1403 << '\n';
	String s1503 = s1203.substr(6, 4);
	std::cout << "s1503 " << s1503 << '\n';
	s1203.insert(6, s1303, 1);
	std::cout << "s1203 " << s1203 << '\n';
	String s1603 = s1203.substr(6, 1000);
	std::cout << "s1603 " << s1603 << '\n';
	std::cout << s1203.find(s1303) << '\n';
	std::cout << s1203.find(s1603) << '\n';
	std::cout << s1203.find("an") << '\n';
	std::cout << s1203.find("xan") << '\n';
	std::cout << s1203.find('a') << '\n';
	std::cout << s1203.find('x') << '\n';
	String s1703('a');
	std::cout << s1203.rfind(s1703) << '\n';
	String s1803("oa");
	std::cout << s1203.rfind(s1803) << '\n';
	std::cout << s1203.rfind("ydd") << '\n';
	std::cout << s1203.rfind('y') << '\n';
	std::cout << s1203.rfind("dd") << '\n';
	const char a563 = 'C';
	std::cout << String(a563) << '\n';
	std::cout << String('Z') << '\n';

	String s1204 ("lkbjdbhf");
	String s1304 ("b");
	s1204.insert(6, s1304);
	std::cout << "s1204 " << s1204 << '\n';
	String s1404 = s1204.substr(6);
	std::cout << "s1404 " << s1404 << '\n';
	String s1504 = s1204.substr(6, 4);
	std::cout << "s1504 " << s1504 << '\n';
	s1204.insert(6, s1304, 1);
	std::cout << "s1204 " << s1204 << '\n';
	String s1604 = s1204.substr(6, 1000);
	std::cout << "s1604 " << s1604 << '\n';
	std::cout << s1204.find(s1304) << '\n';
	std::cout << s1204.find(s1604) << '\n';
	std::cout << s1204.find("an") << '\n';
	std::cout << s1204.find("xan") << '\n';
	std::cout << s1204.find('a') << '\n';
	std::cout << s1204.find('x') << '\n';
	String s1704('a');
	std::cout << s1204.rfind(s1704) << '\n';
	String s1804("oa");
	std::cout << s1204.rfind(s1804) << '\n';
	std::cout << s1204.rfind("hf") << '\n';
	std::cout << s1204.rfind('y') << '\n';
	std::cout << s1204.rfind("dd") << '\n';
	const char a9 = 'c';
	std::cout << String(a9) << '\n';
	std::cout << String('!') << '\n';


	return 0;
}