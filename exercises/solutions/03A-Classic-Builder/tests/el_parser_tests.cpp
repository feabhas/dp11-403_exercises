// el_parser_tests.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Return;
using ::testing::_;
using ::testing::A;
using ::testing::NiceMock;
using ::testing::NaggyMock;
using ::testing::StrictMock;
using ::testing::StartsWith;
using ::testing::ContainsRegex;


#include "EventLogParser.h"
#include "I_DocBuilder.h"
#include "EventLog.h"

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

class EventListParserTest : public ::testing::Test {
protected:
    EventListParserTest()
    {
        // Do set-up work for each test here.
        if(not fs::exists("log.txt")){
            EventLog::setLogFile("log.txt");
            EventLog &log = EventLog::instance();

            log << "First event log entry";
            log << "subsequent entry...";
        }
    }
};

/*
class I_DocBuilder {
public:
  virtual void preamble() = 0;
  virtual void heading(std::string_view str) = 0;
  virtual void subheading(std::string_view str) = 0;
  virtual void body(std::string_view str) = 0;
  virtual void postamble() = 0;
  virtual ~I_DocBuilder() = default;
};
*/
class mock_builder : public I_DocBuilder {
public:
  MOCK_METHOD(void, preamble,());
  MOCK_METHOD(void, heading,(std::string_view str));
  MOCK_METHOD(void, subheading,(std::string_view str));
  MOCK_METHOD(void, body,(std::string_view str));
  MOCK_METHOD(void, postamble,());
};

TEST_F(EventListParserTest, no_builder)
{
    EventLogParser parser{};
    ASSERT_THROW(parser.construct("log.txt"),
                 std::runtime_error);
}

TEST_F(EventListParserTest, no_log_file)
{
    mock_builder mock{};
    EventLogParser parser{};
    bind(parser, mock);
    ASSERT_THROW(parser.construct("nolog.txt"),
                 std::runtime_error);
}


TEST_F(EventListParserTest, initialTest)
{
    NaggyMock<mock_builder> mock{};
    EventLogParser parser{};
    bind(parser, mock);

    EXPECT_CALL(mock, preamble());
    EXPECT_CALL(mock, postamble());
    EXPECT_CALL(mock, heading(_)).Times(2);
    EXPECT_CALL(mock, subheading(_)).Times(2);
    EXPECT_CALL(mock, body(_)).Times(2);


    parser.construct("log.txt");
}


