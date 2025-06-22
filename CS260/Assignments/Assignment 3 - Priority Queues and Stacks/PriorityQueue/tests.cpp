#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <ctime>

#include "PriorityQueue.h"
#include "DataStream.h"

TEST_CASE("1: Testing If Parents Are Greater Than Children.") {
  DataStream d(0);

  PriorityQueue<Packet> testQueue;

  for (int i = 0; i < 16000; i++) {
    Packet p = d.getPacket();
    testQueue.add(p);
  }

  for (int i = 0; i < 8000; i++) {
    CHECK(!(testQueue.getValue(i) < testQueue.getValue(2 * i + 1)));
    CHECK(!(testQueue.getValue(i) < testQueue.getValue(2 * i + 2)));
  }
} TEST_CASE("2: Testing if Remove Properly Works + If Parents Are Greater Than Children") {
  DataStream d(0);

  PriorityQueue<Packet> testQueue;

  for (int i = 0; i < 16000; i++) {
    Packet p = d.getPacket();
    testQueue.add(p);
  } for (int i = 0; i < 8000; i++) {
    CHECK(!(testQueue.getValue(i) < testQueue.getValue(2 * i + 1)));
    CHECK(!(testQueue.getValue(i) < testQueue.getValue(2 * i + 2)));
  } for (int i = 0; i < 8000; i++) {
    testQueue.removeMax();
  } for (int i = 0; i < 4000; i++) {
    CHECK(!(testQueue.getValue(i) < testQueue.getValue(2 * i + 1)));
    CHECK(!(testQueue.getValue(i) < testQueue.getValue(2 * i + 2)));
  }
} TEST_CASE("3: Testing If Queue is Empty If All Items Are Removed") {
  DataStream d(0);

  PriorityQueue<Packet> testQueue;

  for (int i = 0; i < 16000; i++) {
    Packet p = d.getPacket();
    testQueue.add(p);
  }
  CHECK(!(testQueue.isEmpty()));
  for (int i = 0; i < 8000; i++) {
    CHECK(!(testQueue.getValue(i) < testQueue.getValue(2 * i + 1)));
    CHECK(!(testQueue.getValue(i) < testQueue.getValue(2 * i + 2)));
  } for (int i = 0; i < 16000; i++) {
    testQueue.removeMax();
  }
  CHECK(testQueue.isEmpty());
}

