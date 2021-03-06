#pragma once

#include "container.h"
#include "display.h"
#include "timer.h"
#include "queue.h"

#include <memory>
#include <vector>
#include <thread>
#include <string>

extern "C" {
	#include <libavcodec/avcodec.h>
}


class Player {
private:
	std::unique_ptr<Container> container_;
	std::unique_ptr<Display> display_;
	std::unique_ptr<Timer> timer_;

	std::unique_ptr<PacketQueue> packet_queue_;
	std::unique_ptr<FrameQueue> frame_queue_;

	std::vector<std::thread> stages_;

	static const size_t queue_size_ {5};

public:
	Player(const std::string &file_name);
	~Player();

	void demultiplex();
	void decode_video();
	void video();

};
