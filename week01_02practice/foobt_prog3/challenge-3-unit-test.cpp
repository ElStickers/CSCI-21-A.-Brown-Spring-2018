/**********************************************/
/***** Programming Challenge 3  UNIT TEST *****/
/**********************************************/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
 * Unit test. Do not alter.
 */

TEST_CASE("WordList functionality") {

	SECTION("does not allow dupes") {
		WordList w;

		CHECK(w.getWordCount() == 0);
		CHECK(w.hasWord("") == false);
		CHECK(w.removeWord("") == false);
		CHECK(w.toString() == "");

		CHECK(w.addWord("apple") == true);
		CHECK(w.getWordCount() == 1);
		CHECK(w.addWord("apple") == false);
		CHECK(w.getWordCount() == 1);
		CHECK(w.toString() == "[1] apple\n");

		CHECK(w.removeWord("apple") == true);
		CHECK(w.toString() == "");
		CHECK(w.getWordCount() == 0);
	}

	SECTION("allows dupes") {
		WordList w(true);

		CHECK(w.getWordCount() == 0);
		CHECK(w.hasWord("") == false);
		CHECK(w.removeWord("") == false);
		CHECK(w.toString() == "");

		CHECK(w.addWord("apple") == true);
		CHECK(w.getWordCount() == 1);
		CHECK(w.addWord("apple") == true);
		CHECK(w.getWordCount() == 2);
		CHECK(w.toString() == "[1] apple\n[2] apple\n");

		CHECK(w.removeWord("apple") == true);
		CHECK(w.toString() == "[1] apple\n");
		CHECK(w.getWordCount() == 1);

		CHECK(w.removeWord("apple") == true);
		CHECK(w.toString() == "");
		CHECK(w.getWordCount() == 0);
	}

	SECTION("words loaded from file; does not allow dupes") {
		WordList w;

		CHECK(w.loadFile("does-not-exist.txt") == false);

		CHECK(w.loadFile("challenge-3-data.txt") == true);

		CHECK(w.getWordCount() == 7);
		CHECK(w.hasWord("raspberry") == true);
		CHECK(w.hasWord("blackberry") == false);
		CHECK(w.toString() == 
			"[1] orange\n[2] apple\n[3] grape\n[4] banana\n[5] cherry\n[6] kiwi\n[7] raspberry\n");

		w.sort();
		CHECK(w.toString() == 
			"[1] apple\n[2] banana\n[3] cherry\n[4] grape\n[5] kiwi\n[6] orange\n[7] raspberry\n");

		w.clear();
		CHECK(w.getWordCount() == 0);
		CHECK(w.toString() == "");
	}

	SECTION("words loaded from file; allows dupes") {
		WordList w(true);

		CHECK(w.loadFile("challenge-3-data.txt") == true);

		CHECK(w.getWordCount() == 10);
		CHECK(w.hasWord("raspberry") == true);
		CHECK(w.hasWord("blackberry") == false);
		CHECK(w.toString() == 
			"[1] orange\n[2] apple\n[3] grape\n[4] apple\n[5] banana\n"
			"[6] cherry\n[7] cherry\n[8] orange\n[9] kiwi\n[10] raspberry\n");

		w.sort();
		CHECK(w.toString() == 
			"[1] apple\n[2] apple\n[3] banana\n[4] cherry\n[5] cherry\n"
			"[6] grape\n[7] kiwi\n[8] orange\n[9] orange\n[10] raspberry\n");

		w.clear();
		CHECK(w.getWordCount() == 0);
		CHECK(w.toString() == "");
	}

	SECTION("stress test") {
		WordList w(true);

		for (uint32_t i=0; i<100; i++) {
			w.addWord("hello");
		}

		CHECK(w.getWordCount() == 100);

		for (uint32_t i=0; i<100; i++) {
			w.removeWord("hello");
		}

		CHECK(w.hasWord("hello") == false);
		CHECK(w.removeWord("hello") == false);
		CHECK(w.getWordCount() == 0);
	}
}