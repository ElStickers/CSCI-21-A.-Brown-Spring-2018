/**********************************************/
/***** Programming Challenge 3       SPEC *****/
/**********************************************/
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using std::ifstream;
using std::ostringstream;
using std::sort;
using std::string;
using std::vector;

class WordList {
	public:

		/*
		 * Default constructor. By default, will not allow duplicates.
		 * @param newAllowDupes if true, duplicate words will be allowed
		 */
		WordList(bool newAllowDupes=false);

		/*
		 * Add a word to the list.
		 * @param word the word to be added
		 * @return true if the word has been added, else false (duplicate words 
		 *         will not be added if allowDupes is false)
		 */
		bool addWord (string word);
		
		/*
		 * Remove a word from the list.
		 * @param word the word to be removed
		 * @return true if the word is present and removed, else false
		 */
		bool removeWord (string word);
		
		/*
		 * Check to see if a word is in the list.
		 * @param word the word to check for
		 * @return true if the word is present, else false
		 */
		bool hasWord (string word);

		/*
		 * Return the number of words in the list.
		 * @return an integer containing the number of words in the list
		 */
		uint32_t getWordCount ();

		/*
		 * Clear all of the contents of the list.
		 */
		void clear ();

		/*
		 * Sort the words in the list. The words will be sorted in 
		 * lexicographical order which will be case-sensitive.
		 */
		void sort ();

		/*
		 * Load the contents of a file into the list. Assumes that the file 
		 * has one word per line. Will NOT clear the current contents of the 
		 * list.
		 * @param filename the name of the file to load
		 * @return true if the file is successfully processed, else false
		 */
		bool loadFile (string filename);

		/*
		 * Return a string representation of the word list. String will contain 
		 * a numbered list, one word per line.
		 *
		 * EXAMPLE:
		 *
		 * [1] apple
		 * [2] grapefruit
		 * [3] orange
		 *
		 * @return a string representation of the word list
		 */
		string toString ();

	private:
		vector<string> words;
		bool allowDupes;
};

WordList::WordList

bool WordList::addWord ()