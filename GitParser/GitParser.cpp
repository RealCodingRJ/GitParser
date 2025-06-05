#include <iostream>
#include <Windows.h>


static void createCommand(std::string gitCommand) {

	ShellExecuteA(nullptr, "open", gitCommand.c_str(), nullptr, nullptr, SW_SHOWDEFAULT);

}

static void cloneProject(const std::string clonedProject) {

	ShellExecuteA(nullptr, "open", clonedProject.c_str(), nullptr, nullptr, SW_SHOWDEFAULT);

}

static void createDirectoryForProjectGit(std::string commandCD) {

	ShellExecuteA(nullptr, "open", commandCD.c_str(), nullptr, nullptr, SW_SHOWDEFAULT);
}

static void createUsersInput(std::string inputMessage) {

	std::cin >> inputMessage;
}

struct cdCommand {

	std::string cdDir;
};

struct ClonedProd {

	std::string prod;
};

struct CommandRoute{

	std::string route;
};

int main() {


	CommandRoute route;
	ClonedProd prod;
	cdCommand cmdDir;

	createUsersInput(route.route);

	if (route.route == "add") {
		createCommand("git add .");
	}

	if (route.route == "commit") {
		createCommand("git commit -m added Code");
	}

	if (route.route == "Clone") {
		std::cout << "Enter URL: " << std::endl;

		std::cin >> prod.prod;
		cloneProject("git clone " + prod.prod);
	}

	if (route.route == "cd") {

		std::cout << "Enter URL: " << std::endl;
		std::cin >> cmdDir.cdDir;

		createDirectoryForProjectGit("cmd /c cd " + cmdDir.cdDir);

	}

	if (route.route == "All") {

		createCommand("git add -A");
		createCommand("git commit -m added code to route");
		createCommand("git push -u origin main");

	}


	createCommand(route.route);


}