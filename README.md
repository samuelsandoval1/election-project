# Lab 13 - std::unordered_map
Hash tables are one of the most commonly used data structures in software engineering, as is reflected in its frequency of use in technical interview questions for most software positions at many companies. Hash tables are useful for their lookup speed (almost instant, regardless of how many entries are in the table), and purpose of tracking pertinent information about a given key.

## Objective
* To gain introductory familiarity with key-value pairs
* To practice using `std::unordered_map`, `std::pair`, and `std::vector`

## Instructions
The 2020 election is right around the corner! Imagine the votes are in, and you had to implement the vote counting system. Given a .csv file (csv stands for "comma-separated values" and is actually just plain text) that lists a bunch of voters, identified by first and last name, and the full name of the candidates they voted for, which candidate won the popular vote? Was there voter fraud (people trying to vote multiple times)?

`votes.csv` has been provided and contains thousands of voters' entries. On each line, there is the full name of a voter, followed by comma, and the full name of the candiate he/she voted for. The voters' names are meant to be unique, however there may be some suspicious activity! Did any voter try to vote more than once?

This will be a code-along with your instructor. `std::unordered_map`, or the concept of hash tables and key-value pairs in general can be challenging at first, as they are unlike anything you've seen before. So to earn credit on this assignment, just pay attention in class and type along too so you can see the code in action, and have something cool working before the end of class!

## Grading
* (10 points): The lab is completed in class before the end of your section's normal class time, uses `std::unordered_map` to track each candidates' vote count and who has already voted, correctly outputs the winner of the election, and identifies anyone who tried to vote more than once. Demo your code to your instructor before the end of class.
