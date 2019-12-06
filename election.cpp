#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <ctime>

using namespace std;

pair <string, string> GetVote(string line) {
  int position_of_comma = line.find_first_of(",");
  string voter = line.substr(0, position_of_comma);
  string candidate = line.substr(position_of_comma + 1, line.length());
  return make_pair(voter, candidate);
}

vector< pair<string, string> > GetVotes() {
  vector< pair<string, string> > votes;
  ifstream votes_file("votes.csv");
  string line;
  for (string line; getline(votes_file, line);) {
    votes.push_back(GetVote(line));
  }

  return votes;
}

int main(int argc, char* argv[]) {
  vector< pair<string, string> > votes = GetVotes();
  // TODO: Determine who won the election.
}
