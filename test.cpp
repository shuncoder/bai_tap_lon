#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Subject {
    string name;
    float score;
};

struct Student {
    string name;
    vector<Subject> subjects;
};

// Function to calculate the average score of a student
float calculateAverageScore(Student student) {
    float totalScore = 0.0;
    int numSubjects = student.subjects.size();

    for (int i = 0; i < numSubjects; i++) {
        totalScore += student.subjects[i].score;
    }

    return totalScore / numSubjects;
}

// Function to count the number of subjects with scores <5.5 for a student
int countSubjectsBelowThreshold(Student student, float threshold) {
    int numBelowThreshold = 0;
    int numSubjects = student.subjects.size();

    for (int i = 0; i < numSubjects; i++) {
        if (student.subjects[i].score < threshold) {
            numBelowThreshold++;
        }
    }

    return numBelowThreshold;
}

// Function to determine the scholarship rating of a student
int determineScholarshipRating(Student student) {
    float averageScore = calculateAverageScore(student);
    int numBelowThreshold = countSubjectsBelowThreshold(student, 5.5);

    if (numBelowThreshold > 0 || averageScore < 7.0) {
        return 0;
    } else if (averageScore >= 7.0 && averageScore <= 7.99) {
        return 3;
    } else if (averageScore >= 8.0 && averageScore <= 8.99) {
        return 2;
    } else {
        return 1;
    }
}

// Function to output a student's learning results to the screen
void outputStudentResults(Student student) {
    cout << "Student name: " << student.name << endl;

    int numSubjects = student.subjects.size();
    for (int i = 0; i < numSubjects; i++) {
        cout << "Subject " << i+1 << ": " << student.subjects[i].name << " (Score: " << student.subjects[i].score << ")" << endl;
    }

    float averageScore = calculateAverageScore(student);
    cout << "Average score: " << averageScore << endl;

    int numBelowThreshold = countSubjectsBelowThreshold(student, 5.5);
    cout << "Number of subjects with scores <5.5: " << numBelowThreshold << endl;

    int scholarshipRating = determineScholarshipRating(student);
    if (scholarshipRating == 0) {
        cout << "This student is not eligible for a scholarship." << endl;
    } else {
        cout << "Scholarship rating: " << scholarshipRating << endl;
    }
}

// Function to save the student's learning results to a text file
void saveStudentResultsToFile(Student student, string filename) {
    ofstream file(filename);

    file << "Student name: " << student.name << endl;

    int numSubjects = student.subjects.size();
    for (int i = 0; i < numSubjects; i++) {
        file << "Subject " << i+1 << ": " << student.subjects[i].name << " (Score: " << student.subjects[i].score << ")" << endl;
    }

    float averageScore = calculateAverageScore(student);
    file << "Average score: " << averageScore << endl;

    int numBelowThreshold = countSubjectsBelowThreshold(student, 5.5);
    file << "Number of subjects with scores" << endl;
    int main(){
    	
    	return 0;
	}
