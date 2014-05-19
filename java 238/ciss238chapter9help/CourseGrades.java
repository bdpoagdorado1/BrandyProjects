package com.ciss238.problems.c9.p5;

/**
 * Course Grades Class Chapter 9, Programming Challenge 5
 */

public class CourseGrades {
	// Constant for the number of grades
	public final int NUM_GRADES = 4;

	// Array to hold the graded activities
	private GradedActivity[] grades;

	/**
	 * Constructor
	 */

	public CourseGrades() {
		// Create the grades array.
		grades = new GradedActivity[NUM_GRADES];
	}

	/**
	 * setLab method
	 */
	public void setLab(GradedActivity lab) {

		grades[0] = lab;
	}

	/**
	 * setPassFailExam method
	 */

	public void setPassFailExam(PassFailExam aPassFailExam) {
		grades[1] = aPassFailExam;
	}

	/**
	 * setEssay method
	 */

	public void setEssay(Essay anEssay) {
		grades[2] = anEssay;
	}

	/**
	 * setFinalExam method
	 */

	public void setFinalExam(FinalExam aFinalExam) {
		grades[3] = aFinalExam;
	}

	/**
	 * toString method
	 */

	public String toString() {
		String str = "Lab Score: " + grades[0].getScore() + "\tGrade: "
				+ grades[0].getGrade() + "\nPass/Fail Exam Score: "
				+ grades[1].getScore() + "\tGrade: " + grades[1].getGrade()
				+ "\nEssay Score: " + grades[2].getScore() + "\tGrade: "
				+ grades[2].getGrade() + "\nFinal Exam Score: "
				+ grades[3].getScore() + "\tGrade: " + grades[3].getGrade();

		return str;
	}
}
