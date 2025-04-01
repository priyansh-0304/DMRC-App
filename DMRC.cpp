#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <stack>
using namespace std;
class DelhiMetroApp
{
public:
 // Structure to represent a metro station
 struct Station
 {
 string name;
 unordered_map<string, int> neighbors;
 };
 struct Employee
 {
 string username;
 string password;
 bool isAdmin; // Indicates if the employee has admin privileges
 };
 unordered_map<string, Station> metroMap;
 unordered_map<string, Employee> employeeMap;
public:
 // Function to add a new station to the metro map
 void addStation(const string& name)
 {
 Station newStation;
 newStation.name = name;
 metroMap[name] = newStation;
 }
 // Function to add a new metro line between two stations with travel time
 void addMetroLine(const string& station1, const string& station2, int time)
 {
 metroMap[station1].neighbors[station2] = time;
 metroMap[station2].neighbors[station1] = time;
 }
 void writeWelcomePageToFile()
 {
 ofstream welcomeFile("welcome_page.txt");
 if (welcomeFile.is_open())
 {
welcomeFile << " __ __ ___ _ ___ ___ __ __ ___ \n";
welcomeFile << " \\ \\ / /| __|| | / __| / _ \\ | \\/ || __| \n";
welcomeFile << " \\ \\/\\/ / | _| | |__ | (__ | (_) || |\\/| || _| \n";
welcomeFile << " \\_/\\_/ |___||____| \\___| \\___/ |_| |_|___| \n";
welcomeFile << " \n";
welcomeFile << " _____ ___ \n";
welcomeFile << " |_ _| / _ \\ \n";
welcomeFile << " | | | (_) | \n";
welcomeFile << " |_| \\___/ \n";
welcomeFile << " \n";
welcomeFile << " ___ ___ _ _ _ ___ \n";
welcomeFile << " | \\ | __|| | | || ||_ _| \n";
welcomeFile << " | |) || _| | |__ | __ | | | \n";
welcomeFile << " |___/ |___||____||_||_||___| \n";
welcomeFile << " \n";
welcomeFile << " __ __ ___ _____ ___ ___ \n";
welcomeFile << " | \\/ || __||_ _|| _ \\ / _ \\ \n";
welcomeFile << " | |\\/| || _| | | | /| (_) | \n";
welcomeFile << " |_| |_||___| |_| |_|_\\ \\___/ \n";
welcomeFile << " \n";
welcomeFile << " OO O o o o... ______________________ _________________ \n";
welcomeFile << " O ____ | | | | \n";
welcomeFile << " ][_n_i_| ( ooo___ | | | | \n";
welcomeFile << "(__________|_[______]_|____________________|_|_______________| \n";
welcomeFile << " 0--0--0 0 0 0 0 0 0 0 \n";
 welcomeFile.close();
 }
 else
 {
 cerr << "Unable to open file for writing welcome page.\n";
 }
 }
 void displayWelcomePageFromFile()
 {
 ifstream welcomeFile("welcome_page.txt");
 if (welcomeFile.is_open())
 {
 string line;
 while (getline(welcomeFile, line))
 {
 cout << line << endl;
 }
 welcomeFile.close();
 }
 else
 {
 cerr << "Unable to open file for reading welcome page.\n";
 }
 }
 void writeWelcomePageToFile1()
 {
 ofstream welcomeFile("welcome_page1.txt");
 if (welcomeFile.is_open())
 {
welcomeFile << " _____ _ _ ___ _ _ _ __ \n";
welcomeFile << " |_ _|| || |/ \\| \\| || |/ / \n";
welcomeFile << " | | | __ || - || . || < \n";
welcomeFile << " |_| |_||_||_|_||_\\_||_|\\_\\ \n";
welcomeFile << " __ __ ___ _ _ \n";
welcomeFile << " \\ \\ / / / _ \\ | | | | \n";
welcomeFile << " \\ / | (_) || |_| | \n";
welcomeFile << " |_| \\___/ \\___/ \n";
welcomeFile << " ___ ___ ___ \n";
welcomeFile << "| __| / _ \\ | _ \\ \n";
welcomeFile << "| _| | (_) || / \n";
welcomeFile << "|_| \\___/ |_|_\\ \n";
welcomeFile << "__ __ ___ ___ ___ _____ ___ _ _ ___ \n";
welcomeFile << "\\ \\ / /|_ _|/ __||_ _||_ _||_ _|| \\| | / __|\n";
welcomeFile << " \\ / | | \\__ \\ | | | | | | | . || (_ |\n";
welcomeFile << " \\_/ |___||___/|___| |_| |___||_|\_| \\___|\n";
 welcomeFile.close();
 }
 else
 {
 cerr << "Unable to open file for writing welcome page.\n";
 }
 }
 void displayWelcomePageFromFile1()
 {
 ifstream welcomeFile("welcome_page1.txt");
 if (welcomeFile.is_open())
 {
 string line;
 while (getline(welcomeFile, line))
 {
 cout << line << endl;
 }
 welcomeFile.close();
 }
 else
 {
 cerr << "Unable to open file for reading welcome page.\n";
 }
 }
 void clearScreen() {
 #ifdef _WIN32
 system("cls");
 #else
 system("clear");
 #endif
 }
 // Function to find the shortest path between two stations using Dijkstra's algorithm
 vector<string> findShortestPath(const string& startStation, const string& endStation)
 {
 unordered_map<string, int> distance;
 unordered_map<string, string> previous;
 priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int,
string>>> pq;
 for (const auto& entry : metroMap)
 {
 distance[entry.first] = INT_MAX;
 }
 distance[startStation] = 0;
 pq.push({0, startStation});
 while (!pq.empty())
 {
 string current = pq.top().second;
 int currentDistance = pq.top().first;
 pq.pop();
 if (currentDistance > distance[current])
 {
 continue;
 }
 for (const auto& neighbor : metroMap[current].neighbors)
 {
 int newDistance = currentDistance + neighbor.second;
 if (newDistance < distance[neighbor.first])
 {
 distance[neighbor.first] = newDistance;
 previous[neighbor.first] = current;
 pq.push({newDistance, neighbor.first});
 }
 }
 }
 vector<string> path;
 string current = endStation;
 while (!previous[current].empty())
 {
 path.push_back(current);
 current = previous[current];
 }
 path.push_back(startStation);
 reverse(path.begin(), path.end());
 return path;
 }
 // Calculate the fare
 double calculateFare(const vector<string>& path)
 {
 double totalFare = 0.0;
 const double baseFare = 10.0;
 const double farePerKilometer = 5.0;
 int totalDistance = 0;
 for (size_t i = 0; i< path.size() - 1; ++i)
 {
 totalDistance += metroMap[path[i]].neighbors[path[i + 1]];
 }
 totalFare = baseFare + farePerKilometer * totalDistance;
 if (totalFare < 100.0)
 {
 totalFare *= 0.9;
 }
 return ceil(totalFare);
 }
 void displayTravelTime(const vector<string>& path)
 {
 int totalTime = 0;
 for (size_t i = 0; i < path.size() - 1; ++i)
 {
 string currentStation = path[i];
 string nextStation = path[i + 1];
 totalTime += metroMap[currentStation].neighbors[nextStation];
 }
 cout << "Total Travel Time: " << totalTime << " minutes\n";
 }
 // Function to add a Station by employee
 void addStationByEmployee()
 {
 string stationName;
 cout << "Enter the name of the new station: ";
 cin >> stationName;
 addStation(stationName);
 cout << "Station added successfully!\n";
 }
 // Function to add a new metro line by employee
 void addMetroLineByEmployee()
 {
 string station1, station2;
 int time;
 cout << "Enter the names of the two stations connected by the metro line: ";
 cin >> station1 >> station2;
 cout << "Enter the travel time between " << station1 << " and " << station2 << ": ";
 cin >> time;
 addMetroLine(station1, station2, time);
 cout << "Metro line added successfully!\n";
 }
 // Function to register a new employee
 void registerEmployee()
 {
 string newUsername, newPassword;
 cout << "Enter a new username for the employee: ";
 cin >> newUsername;
 cout << "Enter a password for the employee: ";
 cin >> newPassword;
 Employee newEmployee;
 newEmployee.username = newUsername;
 newEmployee.password = newPassword;
 newEmployee.isAdmin = true;
 employeeMap[newUsername] = newEmployee;
 cout << "Employee registered successfully!\n";
 }
 // Function to handle employee login
 bool employeeLogin(const string& username, const string& password)
 {
 auto it = employeeMap.find(username);
 if (it != employeeMap.end() && it->second.password == password)
 {
 cout << "Employee login successful!\n";
 return true;
 }
 else
 {
 cout << "Invalid username or password. Please try again.\n";
 return false;
 }
 }
};
// Function to handle employee actions
void handleEmployeeActions(DelhiMetroApp& metroApp)
{
 int employeeChoice;
 do
 {
 cout << "\nEmployee Actions:\n";
 cout << "1. Add Station\n";
 cout << "2. Add Metro Line\n";
 cout << "3. Logout\n";
 cout << "Enter your choice: ";
 cin >> employeeChoice;
 switch (employeeChoice)
 {
 case 1:
 metroApp.addStationByEmployee();
 break;
 case 2:
 metroApp.addMetroLineByEmployee();
 break;
 case 3:
 cout << "Logging out...\n";
 break;
 default:
 cout << "Invalid choice. Please enter a valid option.\n";
 }
 } while (employeeChoice != 3);
}
void printColoredStation(const string& station, const string& color)
{
 cout << "\033[1;" << color << "m" << station << "\033[0m";
}
int getValidStationNumber(const string& prompt, const DelhiMetroApp& metroApp) {
 int stationNumber;
 stack<string> errorStack;
 do {
 cout << prompt;
 cin >> stationNumber;
 if (stationNumber < 1 || stationNumber > metroApp.metroMap.size()) {
 errorStack.push("Invalid input. Please choose a valid station number.");
 } else {
 return stationNumber;
 }
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 while (!errorStack.empty()) {
 cerr << "Error: " << errorStack.top() << endl;
 errorStack.pop();
 }
 } while (true);
}
int main()
{
 DelhiMetroApp metroApp;
 metroApp.writeWelcomePageToFile();
 metroApp.displayWelcomePageFromFile();
 cout << "\nPress Enter to continue...";
 cin.get();
 metroApp.clearScreen();
 metroApp.addStation("Noida_Sector_62");
 metroApp.addStation("Botanical_Garden");
 metroApp.addStation("Yamuna_Bank");
 metroApp.addStation("Rajiv_Chowk");
 metroApp.addStation("Vaishali");
 metroApp.addStation("Moti_Nagar");
 metroApp.addStation("Janak_Puri_West");
 metroApp.addStation("Dwarka_Sector_21");
 metroApp.addStation("Huda_City_Center");
 metroApp.addStation("Saket");
 metroApp.addStation("Vishwavidyalaya");
 metroApp.addStation("Chandni_Chowk");
 metroApp.addStation("New_Delhi");
 metroApp.addStation("AIIMS");
 metroApp.addStation("Shivaji_Stadium");
 metroApp.addStation("DDS_Campus");
 metroApp.addStation("IGI_Airport");
 metroApp.addStation("Rajouri_Garden");
 metroApp.addStation("Netaji_Subhash_Place");
 metroApp.addStation("Punjabi_Bagh_West");
 metroApp.addMetroLine("Noida_Sector_62", "Botanical_Garden", 8);
 metroApp.addMetroLine("Botanical_Garden", "Yamuna_Bank", 10);
 metroApp.addMetroLine("Yamuna_Bank", "Vaishali", 8);
 metroApp.addMetroLine("Yamuna_Bank", "Rajiv_Chowk", 6);
 metroApp.addMetroLine("Rajiv_Chowk", "Moti_Nagar", 9);
 metroApp.addMetroLine("Moti_Nagar", "Janak_Puri_West", 7);
 metroApp.addMetroLine("Janak_Puri West", "Dwarka_Sector_21", 6);
 metroApp.addMetroLine("Huda_City_Center", "Saket", 15);
 metroApp.addMetroLine("Saket", "AIIMS", 6);
 metroApp.addMetroLine("AIIMS", "Rajiv_Chowk", 7);
 metroApp.addMetroLine("Rajiv_Chowk", "New_Delhi", 1);
 metroApp.addMetroLine("New_Delhi", "Chandni_Chowk", 2);
 metroApp.addMetroLine("Chandni_Chowk", "Vishwavidyalaya", 5);
 metroApp.addMetroLine("New_Delhi", "Shivaji_Stadium", 2);
 metroApp.addMetroLine("Shivaji_Stadium", "DDS_Campus", 7);
 metroApp.addMetroLine("DDS_Campus", "IGI_Airport", 8);
 metroApp.addMetroLine("Moti_Nagar", "Rajouri_Garden", 2);
 metroApp.addMetroLine("Punjabi_Bagh_West", "Rajouri_Garden", 2);
 metroApp.addMetroLine("Punjabi_Bagh_West", "Netaji_Subhash_Place", 3);
 cout << "********************************************\033[1;33mWELCOME TO DELHI "
                 "METRO RAIL CORPORATION\033[0m******************************************"
              << endl;
    cout << " ***************************************" << endl;
 int userChoice;
string username, password;
 do
 {
 cout << "\nWelcome to Delhi Metro Rail Corporation!\n";
 cout << "1. Employee Login\n";
 cout << "2. Employee Register\n";
 cout << "3. Exit\n";
 cout << "Enter your choice: ";
 cin >> userChoice;
 cout << "\nPress Enter to continue...";
 cin.get();
 metroApp.clearScreen();
 switch (userChoice)
 {
 case 1:
 cout << "********************************************\033[1;33mWELCOME TO DELHI"
"METRO RAIL CORPORATION\033[0m******************************************" << endl;
 cout << " ***************************************" << endl;
 cout << "Enter your username: ";
 cin >> username;
 cout << "Enter your password: ";
 cin >> password;
 if (metroApp.employeeLogin(username, password))
 {
 handleEmployeeActions(metroApp);
 cout<<endl;
 cout << "********************************************\033[1;33mWELCOME TO DELHI"
"METRO RAIL CORPORATION\033[0m******************************************" << endl;
 cout << " ***************************************" << endl;
 }
 cout << "\nPress Enter to continue...";
 cin.get();
 metroApp.clearScreen();
 break;
 case 2:
 cout << "********************************************\033[1;33mWELCOME TO DELHI"
"METRO RAIL CORPORATION\033[0m******************************************" << endl;
 cout << " ***************************************" << endl;
 metroApp.registerEmployee();
 cout<<endl;
 cout << "********************************************\033[1;33mWELCOME TO DELHI"
"METRO RAIL CORPORATION\033[0m******************************************" << endl;
 cout << " ***************************************" << endl;
 cout << "\nPress Enter to continue...";
 cin.get();
 metroApp.clearScreen();
 break;
 case 3:
 cout << "Exiting...\n";
 break;
 default:
 cout << "Invalid choice. Please enter a valid option.\n";
 break;
 }
 } while (userChoice != 3);
 cout << "\nList of Metro Stations:\n";
 int stationNumber = 1;
 for (const auto& entry : metroApp.metroMap)
 {
 cout << stationNumber << ". ";
 printColoredStation(entry.first, "32");
 cout << " ";
 cout << endl;
 stationNumber++;
 }
 cout << endl;
 int startStationNumber = getValidStationNumber("\nPlease enter the number "
"corresponding to your START STATION:\n", metroApp);
 int endStationNumber = getValidStationNumber("\nPlease enter the number "
"corresponding to your DESTINATION STATION:\n", metroApp);
 cout << "\nPress Enter to continue... ";
 cin.get();
 metroApp.clearScreen();
 string startStationName, endStationName;
 stationNumber = 1;
 for (const auto& entry : metroApp.metroMap)
 {
 if (stationNumber == startStationNumber)
 {
 startStationName = entry.first;
 }
 if (stationNumber == endStationNumber)
 {
 endStationName = entry.first;
 }
 stationNumber++;
 }
 cout << "\nCalculating the shortest path...\n";
 vector<string> shortestPath = metroApp.findShortestPath(startStationName,
endStationName);
 cout << "\nShortest Path from ";
 printColoredStation(startStationName, "32");
 cout << " to ";
 printColoredStation(endStationName, "34");
 cout << ":\n";
 for (size_t i = 0; i < shortestPath.size(); ++i)
 {
 printColoredStation(shortestPath[i], "33");
 if (i < shortestPath.size() - 1)
 {
 cout << " -> ";
 }
 }
 cout << "\n";
 double fare = metroApp.calculateFare(shortestPath);
 cout << "\nTotal Fare: $" << fare << "\n";
 metroApp.displayTravelTime(shortestPath);
 cout<<endl;
 cout<<endl;
 cout<<endl;
 cout <<
"*****************************************************************************************"
"********************************" <<endl;
 metroApp.writeWelcomePageToFile1();
 metroApp.displayWelcomePageFromFile1();
 return 0;
}
