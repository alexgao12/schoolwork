    #include <iostream>
    #include <vector>
    using namespace std;


    void outputRoster(const vector<int> &, const vector<int> &);
    void addPlayer(vector<int> &, vector<int> &);
    void removePlayer(vector<int> &, vector<int> &);
    void updatePlayerRating(const vector<int> &, vector<int> &);
    void outputPlayersAboveRating(const vector<int> &, const vector<int> &);
    int findIndex(const vector<int>&, int);


    int main() {
        int number, rating;
        char menuChoice;
        vector<int> jerseyNumbers, ratings;

        for(unsigned i = 0; i < 5; ++i){
            cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
            cin >> number;
            jerseyNumbers.push_back(number);
            cout << "Enter player " << i + 1 << "'s rating:" << endl;
            cin >> rating;
            ratings.push_back(rating);
            cout << endl;

            
        }

        outputRoster(jerseyNumbers, ratings);

        while (true){
            cout << "MENU\na - Add player\nd - Remove player\nu - Update player rating\nr - Output players above a rating\no - Output roster\nq - Quit" << endl << endl;
            cout << "Choose an option:";
            cin >> menuChoice;
            cout << endl;

            if (menuChoice == 'a'){
                addPlayer(jerseyNumbers, ratings);
            }   

            if (menuChoice == 'd'){
                removePlayer(jerseyNumbers, ratings);
            }

            if (menuChoice == 'u'){
                updatePlayerRating(jerseyNumbers, ratings);
            }

            if (menuChoice == 'r'){
                outputPlayersAboveRating(jerseyNumbers, ratings);
            }     

            if(menuChoice == 'o'){
                outputRoster(jerseyNumbers, ratings);
            }

            if(menuChoice == 'q'){
                return 0; 
            }
        }
        return 0;
    }

    int findIndex(const vector<int>& jerseyNumbers, int element){
        int index;
        for(unsigned i = 0; i < jerseyNumbers.size(); ++i){
            if(jerseyNumbers.at(i) == element){
                index = i;
            }
        }
        return index;
    }

    void outputRoster(const vector<int>& jerseyNumbers, const vector<int>& ratings){
        cout << "ROSTER" << endl;
        for(unsigned i = 0; i < jerseyNumbers.size(); ++i){
            cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumbers.at(i) << ", Rating: " << ratings.at(i) << endl;
        }
        cout << endl;
    }

    void addPlayer(vector<int>& jerseyNumbers, vector<int>& ratings){
        int number, rating;

        cout << "Enter another player's jersey number:" << endl;
        cin >> number;
        cout << "Enter another player's rating:" << endl;
        cin >> rating;
        cout << endl;

        jerseyNumbers.push_back(number);
        ratings.push_back(rating);
    }

    void removePlayer(vector<int>& jerseyNumbers, vector<int>& ratings){
        int index, number;

        cout << "Enter a jersey number:";
        cin >> number;

        index = findIndex(jerseyNumbers, number);
        jerseyNumbers.erase((jerseyNumbers.begin() + index));
        ratings.erase(ratings.begin() + index);
    }

    void updatePlayerRating(const vector<int>& jerseyNumbers, vector<int>& ratings){
        int index, number, rating;

        cout << "Enter a jersey number:";
        cin >> number;
        cout << "Enter a new rating for player:";
        cin >> rating;
        cout << endl;

        index = findIndex(jerseyNumbers, number);
        ratings.at(index) = rating;
    }

    void outputPlayersAboveRating(const vector<int>& jerseyNumbers, const vector<int>& ratings){
        int rating;
        vector<int> aboveRating;

        cout << "Enter a rating:";
        cin >> rating;
        
        for(unsigned i = 0; i < jerseyNumbers.size(); ++i){
            if (ratings.at(i) > rating){
                aboveRating.push_back(i);
            }
        }
        
        cout << "ABOVE " << rating;
        cout << endl;
        
        for(unsigned i = 0; i < aboveRating.size(); ++i){
            cout << "Player " << aboveRating.at(i) + 1 << " -- Jersey number: " << jerseyNumbers.at(aboveRating.at(i)) << ", Rating: " << ratings.at(aboveRating.at(i)) << endl;
        }
        cout << endl;
    }

