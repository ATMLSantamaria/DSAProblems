//Very simple
//Given a array with result of matches and a similar array with names of the teams that play that matches.

//Determine who won the league

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//T O(N) In just one loop is possible to solve with the help of hash table.
// S O(Winners) winners is number of teams that won at least one match
string tournamentWinner(
  vector<vector<string>> competitions, vector<int> results
) {
  //Iterate across results adding the victories and names
  std::unordered_map<std::string,int> teams_victories;
  std::string current_winner;
  std::string victorious;
  int winner_victories = 0;
  // Keep a pointer, index to the winner in each moment
  

  // Each team play against each other ONCE. Not 2 like in a football league
  int number_of_matches = results.size();

  for (int i = 0; i < results.size();++i) {
    //Get name of winner in each iteration
    if (results[i] == 1) {
      victorious = competitions[i][0];
    } else {
      victorious = competitions[i][1];
    }

    //Insert winner or add victory to the hash table
    auto it = teams_victories.find(victorious);
    if (it != teams_victories.end()) {
      it->second += 1;
    } else {
      teams_victories[victorious] = 1;
    }

    //If number of victories > number of victories of previous winner -> new winner
    if (teams_victories[victorious] > winner_victories) {
      winner_victories = teams_victories[victorious];
      current_winner = victorious;
    }
  }
  
  return current_winner;
}
