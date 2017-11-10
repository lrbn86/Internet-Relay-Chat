#ifndef IRC_SERVER
#define IRC_SERVER

#define PASSWORD_FILE "password.txt"

class IRCServer {
	// Add any variables you need...
	
	private:
		int open_server_socket(int port);

	public:
		void initialize();
};

#endif
