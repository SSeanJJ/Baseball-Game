#include <iostream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class batsman {
private:
	int bcode, innings, notout, runs, hits;
	float batavg;

public:
	//enum Pos
	//{
	//	Pitcher,
	//	First_Base,
	//	Second_Base,
	//	Thrid_Base,
	//	Shortstop,
	//	Catcher,
	//	Left_Fielder,
	//	Center_Fielder,
	//	Right_Fielder

	//};
	int phits, pruns;
	float pbatavg;

	string positions[9] = { "Pitcher", "First_Base", "Second_Base", "Third_Base", "Shortstop", "Catcher", "Left_Fielder", "Center_Fielder", "Right_Fielder" };

	string bname, position;
	int jersey;
	batsman() {
		//srand(time(NULL));  
		position = positions[rand() % 9];
		bcode = rand() % 10000;
		innings = rand() % 50;
		notout = rand() % (innings + 1);
		runs = rand() % 1000;
		hits = rand() % runs;
		jersey = rand() % 10;
		calcavg();
		phits = hits;
		pruns = runs;
		pbatavg = batavg;
	}

	void readdata() {

		calcavg();
	}

	void calcavg() {
		if (innings != notout) {
			batavg = (float)runs / (innings - notout);
		}
		else {
			batavg = runs;
		}
	}

	void displaydata() {
		cout << "Player code: " << bcode << endl;
		cout << "Player name: " << bname << endl;
		cout << "Player position: " << position << endl;
		cout << "Jersey number: " << jersey << endl;
		cout << "Innings played: " << innings << endl;
		cout << "Times not out: " << notout << endl;
		cout << "Runs scored: " << runs << endl;
		cout << "Hits: " << hits << endl;
		cout << "Batting average: " << batavg << endl;
	}
};

int main() {


	batsman team[5];
	cout << "Enter the names of each player!" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Player_" << i + 1 << " name is?" << endl;
		getline(cin, team[i].bname);
	}


	float teamavg = 0.0, teamhits = 0.0, teamruns = 0.0;

	for (int i = 0; i < 5; i++) {
		cout << "Enter details for player " << i + 1 << ":" << endl;
		team[i].readdata();

		teamavg += team[i].pbatavg;
		teamhits += team[i].phits;
		teamruns += team[i].pruns;
		//
		cout << endl;
	}

	teamavg /= 5.0;
	for (int i = 0; i < 5; i++) {
		cout << "Player_" << i + 1 << endl;
		team[i].displaydata();
	}
	cout << "\n";
	cout << "TEAM DATA:" << endl;
	cout << "Team batting average: " << teamavg << endl;
	cout << "Total hits: " << teamhits << endl;
	cout << "Total runs: " << teamruns << endl;

	return 0;
}
