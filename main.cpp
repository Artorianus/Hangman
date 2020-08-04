#include <iostream>
#include <string>
#define ALL(v) v.begin(), v.end()
using namespace std;
const int N = 2e5 + 5;
string word, guessString;
int attempts, guessed[100], cnt, sizeOfWord;
int main()
{
    ios_base::sync_with_stdio(0);
    cout << "Enter the word to guess and number of letter attempts: ";
    cin >> word >> attempts;
    system("cls");
    sizeOfWord = word.size();
    cout << "The number of attempts left is: " << attempts << '\n';
    while( attempts && cnt != sizeOfWord ){
        cout << '\n';
        for( int i = 0; i < sizeOfWord; i++ ){
            if( guessed[i] )
                cout << word[i];
            else
                cout <<'_';
            cout << " ";
        }
        cout << "\n\n" << "Enter a letter or a full word: ";
        cin >> guessString;
        if( guessString.size() == 1 ){
            int pos = word.find( guessString );
            if( pos >= 0 && pos < sizeOfWord ){
                if( guessed[pos] ){
                    cout << "You have already guessed the letter..." << '\n';
                }
                else{
                    cout << "You guessed a letter!" << '\n';
                    for( int i = 0; i < sizeOfWord; i++ ){
                        if( word[i] == guessString[0] )
                            guessed[i]++,
                            cnt++;
                    }
                }
            }
            else{
                cout << "You made a wrong guess and lost an attempt..." << '\n';
                attempts--;
                cout << "Attempts remaining: " << attempts << '\n';
            }
        }
        else{
            if( guessString == word ){
                cnt = sizeOfWord;
            }
            break;
        }
    }
    if( cnt == sizeOfWord ){
            cout << "Congratulations! You guessed the word: " << word << '!';
        }
        else
            cout << "Sorry, you failed to guess the word: " << word;
    return 0;
}
