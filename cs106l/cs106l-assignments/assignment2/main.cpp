/*
 * CS106L Assignment 2: Marriage Pact 婚姻契约
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
std::string kYourName = "Han Yu"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 * 
 * 请随意将此函数（及其下方的函数）的返回类型更改为使用 std::unordered_set。如果进行此更改，请确保同时修改 utils.h 中对应的函数。
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream ifs(filename);
  std::set<std::string> set;
  if(ifs.is_open()){
    std::string line;
    while(std::getline(ifs, line)){
      set.insert(line);
    }
  }
  ifs.close();
  return set;
}

struct initialName{
  char first;
  char second;
};

initialName get_initials(const std::string& name){
  std::stringstream ss(name);
  std::string fst,snd;
  ss >> fst >> snd;
  initialName in{
    static_cast<char>(std::toupper(fst[0])),
    static_cast<char>(std::toupper(snd[0]))
  };
  return in;
}


/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  auto [namefirst, namesecond] = get_initials(name);
  std::queue<const std::string*> q;
  for(const std::string& student: students){
    auto [stufirst, stusecond] = get_initials(student);
    if(namefirst == stufirst && namesecond == stusecond){
      q.push(&student);
    }
  }
  return q;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if(matches.empty())
    return "NO MATCHES FOUND.";
  else
    return *matches.front();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
