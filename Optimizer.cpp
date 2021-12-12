#include"Optimizer.h"

void Optimizer::score()
{
	int resulting_score = 0;
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		resulting_score = 0;
		for (int ii = 0; ii < 8; ii++)
		{
			resulting_score += rules[ii]->grade(population[i]);
		}
		population[i].score = resulting_score;
	}
}

void Optimizer::find_elite()
{
	int smallest_score;
	int index_of_the_smallest_score;
	Schedule temp;
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		smallest_score = population[i].score;
		index_of_the_smallest_score = i;
		for (int ii = i; ii < POPULATION_SIZE; ii++)
		{
			if (population[ii].score < smallest_score)
			{
				smallest_score = population[ii].score;
				index_of_the_smallest_score = ii;
			}
		}
		temp = population[i];
		population[i] = population[index_of_the_smallest_score];
		population[index_of_the_smallest_score] = temp;
	}
	for (int i = 0; i < ELITE_SIZE; i++)
	{
		elite[i] = population[i];
	}
}

void Optimizer::repopulate()
{
	int parent = 0;
	int pop_per_elite = POPULATION_SIZE / ELITE_SIZE;
	for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++)
	{
		for (int i = 0; i < ELITE_SIZE; i++)
		{
			
			for (int ii = 0; ii < pop_per_elite; ii++)
			{
				if (ii == 0)
				{
					population[(i * pop_per_elite + ii)] = elite[i];
					
				}
				else if (ii < 3)
				{
					Schedule elite_temp = elite[i];
					Schedule buffer;
					loader.generate_schedule(buffer);
					elite_temp.split(buffer);
					population[(i * pop_per_elite + ii)] = elite_temp;
				}
				else
				{
					cout << "population ID" << (i * pop_per_elite + ii) << population[i].display() << endl;

					parent = rand() % ELITE_SIZE;	
					population[(i * pop_per_elite + ii)].split(elite[parent]);
				}
			}
		}
		this->score();
		this->find_elite();
		cout << "Iteration number: " << iteration << endl;
		for (size_t i = 0; i < ELITE_SIZE; i++)
		{

			cout << "elite score " << elite[i].score << endl;
		}
		
	}
}

Optimizer::Optimizer()
{
	rules[0] = new Rule_After_Common_Hours;
	rules[1] = new Rule_Back_Back_Classes;
	rules[2] = new Rule_Evening_Morning_Overlap;
	rules[3] = new Rule_Max_Working_Hours;
	rules[4] = new Rule_More_Than_One_Three_Hour_Class_Per_Day;
	rules[5] = new Rule_More_Than_Three_Classes_Per_Day;
	rules[6] = new Rule_More_Than_two_Evenings;
	rules[7] = new Rule_Overlap;
	loader.load();
	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		loader.generate_schedule(population[i]);
		cout << population[i].display();
	}
	this->score();
	this->find_elite();
}
