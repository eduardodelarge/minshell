# minishell

# add a submodule
  git submodule add <github-link.git>

# Clone the project with submodules
git clone <link.git> --recurse-submodules

# Download the submodules once you already had the main project
git submodule update --init
  ("git submodule init" & "git submodule update")

install readline
	sudo apt-get install libreadline-dev