#pragma once
// Parameters
#include <string>
const int POPULATION_SIZE = 100;
const int ELITE_SIZE = 20;
const int MAX_ITERATIONS = 1000;
const int STABLE_ITERATIONS = 5;

// Rules' weights
const int OVERLAP = 1000000;
const int MAX_WORKING_HOURS = 100;
const int EVENING_MORNING_OVERLAP = 100;
const int MORE_THAN_TWO_EVENINGS = 50;
const int BACK_TO_BACK_CLASSES = 50;
const int AFTER_COMMON_HOUR = 50;
const int MORE_THAN_THREE_CLASSES_PER_DAY = 50;
const int MORE_THAN_ONE_THREE_HOUR_CLASS_PER_DAY = 1000;

// File's destenation 
const std::string FILE_NAME = "sections.txt";