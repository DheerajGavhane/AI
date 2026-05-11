#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Convert string to lowercase
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {

    string input;

    cout << "Hello! I am Customer Support Bot." << endl;
    cout << "How can I help you today?" << endl;
    cout << "You can ask about: order, payment, delivery, or exit." << endl;

    while (true) {

        cout << "You: ";
        getline(cin, input);

        input = toLowerCase(input);

        if (input.find("hello") != string::npos ||
            input.find("hi") != string::npos) {

            cout << "Bot: Hello! How can I assist you?" << endl;

        } 
        else if (input.find("order") != string::npos) {

            cout << "Bot: You can place your order through our website or mobile app." << endl;

        } 
        else if (input.find("payment") != string::npos) {

            cout << "Bot: We accept credit cards, debit cards, and online payment methods." << endl;

        } 
        else if (input.find("delivery") != string::npos) {

            cout << "Bot: Delivery usually takes 3-5 business days." << endl;

        } 
        else if (input.find("help") != string::npos) {

            cout << "Bot: I can help you with orders, payments, and delivery information." << endl;

        } 
        else if (input.find("exit") != string::npos) {

            cout << "Bot: Thank you for chatting. Have a great day!" << endl;
            break;

        } 
        else {

            cout << "Bot: Sorry, I didn't understand that. Please try again." << endl;
        }
    }

    return 0;
}
/*
hello
I want to place an order
payment methods?
delivery time please
help me
exit
Types of Chatbots
    1. Rule-Based Chatbots
    Follow predefined rules
    Simple decision-making
    Limited responses
    2. AI-Based Chatbots
    Use machine learning
    Understand natural language
    Generate intelligent responses
Applications of Chatbots
    Industry	Use
    E-commerce	Product suggestions
    Healthcare	Symptom checking
    Banking	Balance inquiry
    Education	Student assistance
    Travel	Booking support
Advantages of Chatbots
    24/7 availability
    Fast response
    Reduces human workload
    Cost efficient
    Handles multiple users
Limitations of Chatbots
    Poor understanding of complex queries
    Limited domain knowledge
    No real human emotions
    Depends on predefined logic
*/