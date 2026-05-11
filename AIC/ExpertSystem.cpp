#include <iostream>
#include <string>
using namespace std;

int main() {

    string fever, cough, headache, bodyPain, vomiting;

    cout << "===== Hospital Expert System =====" << endl;
    cout << "Answer the following questions with yes or no" << endl;

    cout << "Do you have Fever? ";
    cin >> fever;

    cout << "Do you have Cough? ";
    cin >> cough;

    cout << "Do you have Headache? ";
    cin >> headache;

    cout << "Do you have Body Pain? ";
    cin >> bodyPain;

    cout << "Do you have Vomiting? ";
    cin >> vomiting;

    cout << "\n----- Diagnosis Result -----" << endl;

    // Convert to lowercase logic not needed since we assume yes/no input

    if (fever == "yes" && cough == "yes") {

        cout << "Possible Disease: Flu" << endl;
        cout << "Advice: Take rest and drink warm fluids." << endl;

    } 
    else if (fever == "yes" && headache == "yes" && bodyPain == "yes") {

        cout << "Possible Disease: Dengue" << endl;
        cout << "Advice: Consult a doctor and take a blood test." << endl;

    } 
    else if (vomiting == "yes" && headache == "yes") {

        cout << "Possible Disease: Food Poisoning" << endl;
        cout << "Advice: Drink clean water and consult a doctor." << endl;

    } 
    else if (cough == "yes" && headache == "yes") {

        cout << "Possible Disease: Common Cold" << endl;
        cout << "Advice: Take proper rest and warm liquids." << endl;

    } 
    else {

        cout << "Disease not identified." << endl;
        cout << "Please consult a doctor for accurate diagnosis." << endl;
    }

    return 0;
}
/*
An expert system is an AI-based program that simulates the decision-making ability of a human expert using a knowledge base and inference rules.
Start
  ↓
Input Symptoms
  ↓
Knowledge Base Rules
  ↓
Inference Engine Processing
  ↓
Match Disease
  ↓
Display Result
  ↓
End

Advantages of Expert System
    Fast decision making
    Consistent diagnosis
    Reduces human workload
    Works 24/7
Limitations
    No real human reasoning
    Limited to stored rules
    Cannot handle unknown cases
    Needs frequent updates