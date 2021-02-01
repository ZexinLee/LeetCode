     apt update -y
     apt upgrade -y
     apt install vim htop tmux git -y
     apt install zsh -y
     wget https://github.com/ehang-io/nps/releases/download/v0.26.9/linux_386_server.tar.gz
     tar zvxf linux_386_server.tar.gz
     mkdir nps
     mv linux_386_server.tar.gz nps
     cd nps
     tar zvxf linux_386_server.tar.gz
     ./nps install
     nps start
     sh -c "$(wget https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"
     git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
     git clone https://github.com/zsh-users/zsh-autosuggestions ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-autosuggestions
     wget https://raw.githubusercontent.com/ZexinLi0w0/LeetCode/master/.zshrc
     cp .zshrc /root/.zshrc 
     zsh
