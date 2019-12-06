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
  unordered_map<string, int> results;
  unordered_map<string, int> audit;


  for (int i = 0; i < votes.size(); i++) {
    pair<string, string> vote = votes.at(i);
    string voter = vote.first;
    string candidate = vote.second;
    if(audit.find(candidate) == audit.end()) {
      if(results.find(candidate) == results.end()) {
        results[candidate] = 0;
      }
      results[candidate] += 1;
      audit[voter] = 1;
    }
    else {
      audit[voter] += 1;
    }
  }
  vector<pair<string,int>> vectored_results;
  for(pair<string, int> result : results) {
      cout << result.first << " had " << result.second << " votes" << endl;
      vectored_results.push_back(result);
  }
  pair<string, int> frontrunner = vectored_results.at(0);
  for(int i = 0; i < vectored_results.size(); i++){
    pair<string, int> candidate = vectored_results.at(i);
      if(candidate.second > frontrunner.second) {
        frontrunner = candidate;
      }
  }
  cout << frontrunner.first << " won with "
       << frontrunner.second << " votes." << endl;
  for(pair<string, int> voter: audit) {
    if(voter.second > 1){
      cout << voter.first << " tried to vote " << voter.second-1 << " extra times" << endl;
    }
  }
}
