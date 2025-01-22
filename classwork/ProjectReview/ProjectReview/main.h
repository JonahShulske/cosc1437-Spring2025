#pragma once

void ReadFile(vector<Person>& People, string fileName);

void WriteFile(const vector<Person>& People, string fileName);

void SortVector(vector<Person>& People, int sortType);

bool SortByAge(int a, int b);

bool SortByName(string a, string b);

void Swap(Person & p1, Person & p2);

void DisplayVector(const vector<Person>& People);
