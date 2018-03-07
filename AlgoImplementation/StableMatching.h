// ----------------------------------
// adventures of noella tries to code
// the Gale-Shapley Algorithm
// in the language of the devil's son
// * cries in C++ *
// ----------------------------------

#ifndef StableMatching_h
#define StableMatching_h

#include <iostream>
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <list>
#include <new>

template<std::size_t N>
class StableMatching {

private:

	const int NOT_ENGAGED = -1;
	// int array to hold mens preferences 
	// row is man, column is woman & preference
	int mensPref[N][N];
	// int array to hold womens preferences
	// row is woman, column is man & preference
	int womensPref[N][N];
	//list to hold all of the free men
	std::list<int> freeMenList;
	//array to hold the index of the next woman to propose
	int next[N];
	//array to hold every woman's current engaged partner
	int current[N];
	//2D array to hold all of the rankings per men for each woman
	int ranking[N][N];

public:

	StableMatching(int inputMensPref[N][N], int inputWomensPref[N][N]) :
			freeMenList(0, 0) {
		for (std::size_t i = 0; i < N; i++) {
			for (std::size_t j = 0; j < N; j++) {
				mensPref[i][j] = inputMensPref[i][j];
				womensPref[i][j] = inputWomensPref[i][j];
			}
		}
		for (std::size_t i = 0; i < N; i++) {
			for (std::size_t j = 0; j < N; j++) {
				ranking[i][womensPref[i][j]] = j;
			}
		}
		for (std::size_t i = 0; i < N; i++) {
			freeMenList.push_back(i);
			next[i] = 0;
			current[i] = -1;
		}

	}

	StableMatching() :
			freeMenList(0, 0) {
		for (std::size_t i = 0; i < N; i++) {
			freeMenList.push_back(i);
			next[i] = 0;
			current[i] = -1;
		}
	}

	void getStablePairs() {
		//while there are still free men available
		while (freeMenList.size() > 0) {
			//get the first free man (front of the list)
			int freeMan = freeMenList.front();
			//get the next woman to propose to in that man's list
			int nextWoman = mensPref[freeMan][next[freeMan]];
			//if that woman is not currently engaged, make them a couple
			if (current[nextWoman] == -1) {
				//set the woman's current partner as the free man
				current[nextWoman] = freeMan;
				//increment the free man's next possible partner
				next[freeMan]++;
				//remove the free man from the free men's list
				freeMenList.pop_front();
			} else { //the woman is currently engaged to another man
				//get the woman's current partner
				int curPartner = current[nextWoman];
				//see if the woman's preference for the free man is more
				//than her current partner
				if (ranking[nextWoman][freeMan]
						< ranking[nextWoman][curPartner]) {
					//if ranking is greater, the woman will get engaged to free man
					current[nextWoman] = freeMan;
					//remove free man from the list
					freeMenList.pop_front();
					//add the ex fiancee to the list
					freeMenList.push_front(curPartner);
					//increment the free man's next possible partner
					next[freeMan]++;
				} else {
					//ranking is less than so the woman will stay with her current partner
					next[freeMan]++;
				}
			}
		}
	}

	/*
	 Refer page 545 in the TIC2Vone book
	 */

	friend std::ostream& operator<<(std::ostream& os,
			const StableMatching& sm) {
		for (std::size_t i = 0; i < N; i++) {
			os << "woman: " << i << " man: " << sm.current[i] << std::endl;
		}
		return os;
	}

	friend std::istream& operator>>(std::istream& is, StableMatching& sm) {
		for (std::size_t i = 0; i < N; i++) {
			for (std::size_t j = 0; j < N; j++) {
				is >> sm.mensPref[i][j];
			}
		}
		for (std::size_t i = 0; i < N; i++) {
			for (std::size_t j = 0; j < N; j++) {
				is >> sm.womensPref[i][j];
			}
		}
		for (std::size_t i = 0; i < N; i++) {
			for (std::size_t j = 0; j < N; j++) {
				sm.ranking[i][sm.womensPref[i][j]] = j;
			}
		}
		return is;
	}

};

#endif //StableMatching_h
