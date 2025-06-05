#include <iostream>
#include <Windows.h>


void printRoutedMessage(const std::string routedMessage);
void printRoutedMessage(const std::string routedMessage) {

	std::cout << routedMessage << std::endl;

}

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

struct NameInitProject {

	std::string initProject;
};

struct cdCommand {

	std::string cdDir;
};

struct ClonedProd {

	std::string prod;
};

struct BranchCheckout {
	std::string branchID;
};

struct CommandRoute{

	std::string route;
};

int main() {


	CommandRoute route;
	ClonedProd prod;
	cdCommand cmdDir;
	BranchCheckout checkout;
	NameInitProject initProject;

	printRoutedMessage("Enter Route to Pick: ");
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

	if (route.route == "init") {

		printRoutedMessage("Enter Name for Branch: ");

		std::cin >> initProject.initProject;

		createCommand("git init " + initProject.initProject);

	}

	if (route.route == "branch") {

		printRoutedMessage("Enter Name for Branch: ");

		std::cin >> checkout.branchID;

		createCommand("git checkout -b " + );
	}


	system("pause > 0");
	return 0;
}