#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool wordpattern(string &pattern, string &str);
bool wordpattern2(string &pattern, string &str);

bool wordpattern(string &pattern, string &str){
  vector<size_t> idx;
  unordered_map<char, vector<size_t> > dict;
  vector<string> strVec;
  for(size_t i = 0; i < pattern.size(); i++)
    dict[pattern[i]].push_back(i);
  string bufstr = str;
  size_t iter = 0;
  size_t found = 0;
  do{
    found = bufstr.find(" ");
    strVec.push_back(bufstr.substr(0, found));
    bufstr.erase(0, found+1);
    iter++;
  }while(found != string::npos);
  if(pattern.size() != strVec.size())
    return false;

  unordered_map<char, vector<size_t> >::iterator it = dict.begin();
  for(; it != dict.end(); it++){
    string BUF = " ";
    for(vector<size_t>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
      if(BUF == " "){
        BUF = strVec[*it2];
        size_t Count = count(strVec.begin(), strVec.end(), BUF);
        if( Count != it->second.size())
          return false;
      }else if(BUF != strVec[*it2]){
        return false;
      }
    }
  }
  return true;
}

bool wordpattern2(string &pattern, string &str){
  vector<size_t> idx;
  unordered_map<char, string > dict;
  string bufstr = str;
  size_t iter = 0;
  size_t found = 0;
  do{
    if(iter > pattern.size() -1)
      return false;
    found = bufstr.find(" ");
    unordered_map<char, string>::const_iterator it = dict.find(pattern[iter]);
    if(it == dict.end())
      dict[pattern[iter]] = bufstr.substr(0, found);
    else
      if(it->second != bufstr.substr(0, found))
        return false;
    bufstr.erase(0, found+1);
    iter++;
  }while(found != string::npos);
  if(iter != pattern.size())
    return false;
  unordered_map<string, size_t> checklist;
  size_t num;
  for(unordered_map<char, string>::const_iterator it1 = dict.begin(); it1 != dict.end(); it1++){
    num = ++checklist[it1->second];
    if(num > 1)	
      return false;
  }
  return true;
}

int main(){

  string pattern = "abba";
  string str = "dog dog dog dog";
  //string str = "haha dog apple uuuu uuuu apple dog haha";
  if(wordpattern2(pattern, str))	
    cout << "================="  << endl;

  return 0;
}
