#pragma once
#include "Queue.h"
#include "Stack.h"
#include <string>
#include <sstream> //for ToString to convert messages to a readable string..
#include <chrono>
#include <ctime>
#include <cstring>
using std::stringstream;
using std::string;
class Message
{
public:
	string text;
	bool sent;
	std::time_t created_date;
	string ToString()
	{
		Message m = *this;
		string message = "";
		//Print the date above the message.
		message += "[";
		if (m.sent == true)
			message += "Sent: ";
		else
			message += "Received: ";
		string datetime = TimeToString();
		message += datetime + "] ";
		//Print the text on a new line.
		message += "\n" + m.text;
		return message;
	}
	void SetDateToNow()
	{
		auto start = std::chrono::system_clock::now();
		auto legacyStart = std::chrono::system_clock::to_time_t(start);
		created_date = legacyStart;
	}
	Message() { SetDateToNow(); }
private:
	string TimeToString()
	{
		char tmBuff[30];
		ctime_s(tmBuff, sizeof(tmBuff), &created_date);
		remove_newline(tmBuff);
		stringstream ss;
		ss << tmBuff;
		return ss.str();
	}
	void remove_newline(char* str) {
		int len = strlen(str);
		if (len > 0 && str[len - 1] == '\n') {
			str[len - 1] = '\0';
		}
	}
};
class Messages
{
private:
	Queue<Message> sent;
	Queue<Message> received;
	string contact_name;
public:
	Messages(string contact_name)
	{
		SetContact(contact_name);
	}
	void SetContact(string contact_name)
	{
		this->contact_name = contact_name;
	}
	void SendMessage(string message)
	{
		Message m;
		m.text = message;
		m.sent = true;
		m.created_date = time(nullptr);
		sent.Enqueue(m);
	}
	void ReceiveMessage(string message)
	{
		Message m;
		m.text = message;
		m.sent = false;
		m.created_date = time(nullptr);
		received.Enqueue(m);
	}
	string PrintHistory()
	{
		//Flag is set true when there are no more
		//sent or receive messages to scan.
		bool done = false;
		//Create a Stack/Queue to print the reversed order history.
		Stack<Message> order_history;
		//call it "order_history"
		//_______________________________________
		//Duplicate the sent/received queues so that way they are preserved.
		//ONLY remove from these queues....
		Queue<Message> sent_copy, received_copy;
		sent_copy.CloneDeque(sent);
		received_copy.CloneDeque(received);
		//Stores the next messages removed from the sent/received queues.
		Message next_sent, next_received;
		//Remove the first messages at the front of the sent/received queues.
		bool next_sent_popped = sent_copy.Dequeue(next_sent);
		bool next_received_popped = received_copy.Dequeue(next_received);
		//Fill in the loop below to complete the program.
		do
		{
			if (next_sent_popped && next_received_popped)
			{
				if (difftime(next_sent.created_date, next_received.created_date) <= 0)
				{
					order_history.Push(next_sent);
					next_sent_popped = sent_copy.Dequeue(next_sent);
				}
				else
				{
					order_history.Push(next_received);
					next_received_popped = received_copy.Dequeue(next_received);
				}
			}
			else if (next_sent_popped)
			{
				order_history.Push(next_sent);
				next_sent_popped = sent_copy.Dequeue(next_sent);
			}
			else if (next_received_popped)
			{
				order_history.Push(next_received);
				next_received_popped = received_copy.Dequeue(next_received);
			}
			else
			{
				done = true;
			}
			
		} while (!done);
		//Ouptut the messages in REVERSE order.
		string output = "";
		Message next;
		stringstream ss;
		ss << "Recepient Name: " << contact_name << "\n\n";
		while (order_history.Pop(next))
		{
			output = next.ToString();
			ss << output + "\n\n";
		}
		return ss.str();
	}
};
