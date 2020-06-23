#ifndef TEST_MACROS_H
#define TEST_MACROS_H

#ifndef SIMDJSON_BENCHMARK_DATA_DIR
#define SIMDJSON_BENCHMARK_DATA_DIR "jsonexamples/"
#endif
const char *TWITTER_JSON = SIMDJSON_BENCHMARK_DATA_DIR "twitter.json";
const char *TWITTER_TIMELINE_JSON = SIMDJSON_BENCHMARK_DATA_DIR "twitter_timeline.json";
const char *REPEAT_JSON = SIMDJSON_BENCHMARK_DATA_DIR "repeat.json";
const char *AMAZON_CELLPHONES_NDJSON = SIMDJSON_BENCHMARK_DATA_DIR "amazon_cellphones.ndjson";

#define SIMDJSON_BENCHMARK_SMALLDATA_DIR SIMDJSON_BENCHMARK_DATA_DIR "small/"

const char *ADVERSARIAL_JSON = SIMDJSON_BENCHMARK_SMALLDATA_DIR  "adversarial.json";
const char *FLATADVERSARIAL_JSON = SIMDJSON_BENCHMARK_SMALLDATA_DIR  "flatadversarial.json";
const char *DEMO_JSON = SIMDJSON_BENCHMARK_SMALLDATA_DIR  "demo.json";
const char *SMALLDEMO_JSON = SIMDJSON_BENCHMARK_SMALLDATA_DIR  "smalldemo.json";
const char *TRUENULL_JSON = SIMDJSON_BENCHMARK_SMALLDATA_DIR  "truenull.json";

// For the ASSERT_EQUAL macro
template<typename T>
bool equals_expected(T actual, T expected) {
  return actual == expected;
}
template<>
bool equals_expected<const char *>(const char *actual, const char *expected) {
  return !strcmp(actual, expected);
}

#define TEST_START() { cout << "Running " << __func__ << " ..." << endl; }
#define ASSERT_EQUAL(ACTUAL, EXPECTED) do { auto _actual = (ACTUAL); auto _expected = (EXPECTED); if (!equals_expected(_actual, _expected)) { std::cerr << "Expected " << #ACTUAL << " to be " << _expected << ", got " << _actual << " instead!" << std::endl; return false; } } while(0);
#define ASSERT_ERROR(ACTUAL, EXPECTED) do { auto _actual = (ACTUAL); auto _expected = (EXPECTED); if (_actual != _expected) { std::cerr << "FAIL: Unexpected error \"" << _actual << "\" (expected \"" << _expected << "\")" << std::endl; return false; } } while (0);
#define ASSERT(RESULT, MESSAGE) if (!(RESULT)) { std::cerr << MESSAGE << std::endl; return false; }
#define RUN_TEST(RESULT) if (!RESULT) { return false; }
#define ASSERT_SUCCESS(ERROR) do { auto _error = (ERROR); if (_error) { std::cerr << _error << std::endl; return false; } } while(0);
#define TEST_FAIL(MESSAGE) { std::cerr << "FAIL: " << (MESSAGE) << std::endl; return false; }
#define TEST_SUCCEED() { return true; }

#endif // TEST_MACROS_H