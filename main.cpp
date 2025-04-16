#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>
#include <algorithm>
using namespace std;

string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    system("cls");

  
    //   system("start python show_vira_ui.py"); //This will display the image of VIRA input by python 

    string greet = "Welcome to VIRA voice assistant! How can I help you?";
    string greetCmd = "espeak -ven+m3 -s200 -g10 \"" + greet + "\"";// Turned it's voice into a female plus reduced the speed of speaking since it was fast
    system(greetCmd.c_str());
    //Song database map

    map<string, string> songs = {
        {"faded", "https://www.youtube.com/watch?v=SlPhMPnQ58k"},
        {"shape of you", "https://www.youtube.com/watch?v=JGwWNGJdvx8"},
        {"perfect", "https://www.youtube.com/watch?v=2Vv-BfVoq4g"},
        {"unstoppable", "https://www.youtube.com/watch?v=UceaB4D0jpo"},
        {"despacito", "https://www.youtube.com/watch?v=kJQP7kiw5Fk"},
        {"see you again", "https://www.youtube.com/watch?v=RgKAFK5djSk"},
        {"memories", "https://www.youtube.com/watch?v=CuklIb9d3fI"},
        {"uptown funk", "https://www.youtube.com/watch?v=OPf0YbXqDm0"},
        {"love the way you lie", "https://www.youtube.com/watch?v=uelHwf8o7_U"},
        {"raataan lambiyan", "https://www.youtube.com/watch?v=gvyUuxdRdR4"},
        {"param sundari", "https://www.youtube.com/watch?v=QkZxoko_HC0"},
        {"nadiyon paar", "https://www.youtube.com/watch?v=K0eDlFX9GMc"},
        {"kusu kusu", "https://www.youtube.com/watch?v=PeQWPRxn5wE"},
        {"zaroori tha", "https://www.youtube.com/watch?v=JYa6Miqh8Ls"},
        {"lahore", "https://www.youtube.com/watch?v=dZ9pD9e0IUI"},
        {"zaalima", "https://www.youtube.com/watch?v=hhdSyBHuI88"},
        {"kabira", "https://www.youtube.com/watch?v=jHNNMj5bNQw"},
        {"tera ban jaunga", "https://www.youtube.com/watch?v=VOLKJJvfAbg"},
        {"ghungroo", "https://www.youtube.com/watch?v=prwUFBsDRLk"}
    };

    while (true) {
        string option;
        cout<<"Type :\n Y : Start Listening\n N : Exit\n\n Option = ";
        cin>>option;
        if (option == "Y" || option == "y"){
            system("start python voice_test.py");// This will take voice input which has been given in python 
            Sleep(9500);

            ifstream file("command.txt");
            string command;
            getline(file, command);

            string filename = "command.txt";
            ofstream file2;
            file2.open(filename, ios::trunc);
            if (file2.is_open()){
            file2 << "";
            file2.close();}

            command = toLower(command);
            cout << "\nCommand: " << command << "\n\n";
            cout << "---------------------------------\n\n";
            file.close();

            if (command.find("play") == 0) {
                string songName = command.substr(5);
                if (songs.count(songName)) {
                    string phrase = "Playing " + songName + " on YouTube";
                    string commandSpeak = "espeak -ven+m3 -s200 -g10 \"" + phrase + "\"";
                    system(commandSpeak.c_str());
                    system(("start \"\" \"" + songs[songName] + "\"").c_str());
                } else {
                    system("espeak -ven+m3 -s200 -g10 \"Sorry, I couldn't find that song.\"");
                }
            } else if (command == "open google") {
                system("espeak -ven+m3 -s200 -g10 \"Opening Google\""); system("start https://www.google.com");
            } else if (command == "open youtube") {
                system("espeak -ven+m3 -s200 -g10 \"Opening YouTube\""); system("start https://www.youtube.com");
            } else if (command == "open facebook") {
                system("espeak -ven+m3 -s200 -g10 \"Opening Facebook\""); system("start https://www.facebook.com");
            } else if (command == "open linkedin") {
                system("espeak -ven+m3 -s200 -g10 \"Opening LinkedIn\""); system("start https://www.linkedin.com");
            } else if (command == "how are you" || command == "what's up") {
                system("espeak -ven+m3 -s200 -g10 \"I am great, how about you dear?\"");
            } else {
                system("espeak -ven+m3 -s200 -g10 \"Sorry Human, I did not understand that command\"");
            }
        }
        else if (option == "N" || option == "n"){
            system("espeak -ven+m3 -s200 -g10 \"Hope i assisted you right Goodbye. Call me anytime I'm right there for you Human.\"");
            cout<<"-----------------------------";
            cout<<"\n    Thanks for using VIRA    \n";
            cout<<"-----------------------------";

            break;
        }
        else {
            cout<<"\nSorry!! Invalid Command";
        }
   }

    return 0;
}
