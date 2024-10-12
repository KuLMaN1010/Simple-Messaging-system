#include "Messenger.h"
#include <thread>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
int main()
{
	int base_time = 1250;
	Messages conversation("Natalie");
	conversation.SendMessage("Hey how are you?");
	sleep_for(milliseconds(base_time));
	conversation.ReceiveMessage("Good, how are you?");
	sleep_for(milliseconds(base_time));
	conversation.SendMessage("Good! Did you hear about the weather?");
	sleep_for(milliseconds(base_time));
	conversation.ReceiveMessage("Yes, it looks like there's a storm coming.");
	sleep_for(milliseconds(base_time));
	conversation.SendMessage("Yep. Be safe!");
	sleep_for(milliseconds(base_time));
	conversation.ReceiveMessage("You too");
	sleep_for(milliseconds(base_time));
	conversation.SendMessage("Anyways, had a question if you have a minute.");
	sleep_for(milliseconds(base_time));
	conversation.ReceiveMessage("Sure. What's up?");
	sleep_for(milliseconds(base_time));
	conversation.SendMessage("I know we talked about our get together for Thursday.");
	sleep_for(milliseconds(base_time));
	conversation.SendMessage("But something came up. My father needs my help at his business on that day and I can\'t make it.");
	sleep_for(milliseconds(base_time));
	conversation.SendMessage("Would next Thursday work for you? I apologize for needing to reschedule.");
	sleep_for(milliseconds(base_time));
	conversation.SendMessage("Let me know if you need another date.");
	sleep_for(milliseconds(base_time));
	conversation.ReceiveMessage("I can\'t do next Thursday, but how\'s next Friday at 1:30 sound ? ");
	sleep_for(milliseconds(base_time));
	conversation.ReceiveMessage("Or what about Saturday for dinner? The husband will be out of town then.");
	sleep_for(milliseconds(base_time));
	conversation.SendMessage("Saturday sounds good! Maybe we can go catch a movie afterwards.");
	sleep_for(milliseconds(base_time));
	conversation.ReceiveMessage("Sounds good! See you then.");
	sleep_for(milliseconds(base_time));
	cout << conversation.PrintHistory() << "\n";
}
