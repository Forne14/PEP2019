#!/bin/bash

##########################################################################
############################ COLORED OUTPUT ##############################
ESC_SEQ="\x1b["
COL_RESET=$ESC_SEQ"39;49;00m"
COL_RED=$ESC_SEQ"31;01m"
COL_GREEN=$ESC_SEQ"32;01m"
COL_YELLOW=$ESC_SEQ"33;01m"

function warning() {
    echo -e $COL_RED$1$COL_RESET
}

function success() {
    echo -e $COL_GREEN$1$COL_RESET
}

function info() {
    echo -e '\n'$COL_YELLOW$1$COL_RESET
}
##########################################################################

# set current working directory
cwd=$(mktemp -d)
info 'Created temporary directory '$cwd

# set username and password
info "Log in to Github API"
authorized=false
while [ $authorized = false ]
  do
    read -p "Enter github username (case-sensitive): " username
    read -sp "Enter github password $(printf '\xF0\x9F\x94\x91') " password
    echo # disabling local echo above (-s) gobles up new line
    response=$(curl --silent --user $username:$password https://api.github.com/user)
    message=$(echo $response | python -c "import sys, json; print(json.load(sys.stdin).get('message'))")
    if [ "$message" = None ]; 
    then 
      authorized=true
      name=$(echo $response | python -c "import sys, json; print(json.load(sys.stdin).get('name'))")
      email=$(curl --silent --user $username:$password https://api.github.com/user/emails | python -c "import sys, json; print(json.load(sys.stdin)[0].get('email'))")
      success "Log in successful"
    else warning "$message"
    fi
  done

# set foldername
info 'Set repository name'
foldername=5CCS2PEP
read -p "Enter repository/folder name to store the files (default:$foldername leave blank): " response
if [ "$response" != "" ]; then # trim/strip response
  foldername=$response
fi

folderpath=$cwd/$foldername
mkdir -p $folderpath

# download files
info 'Cloninig repositories...'
for i in {0..10}
  do
    echo "Cloning https://github.com/5CCS2PEP/assignment2018$i-$username ..."
    assignment_path=$folderpath/assignment-$(printf "%02d" $i)
    git clone https://$username:$password@github.com/5CCS2PEP/assignment2018$i-$username $assignment_path
    rm -rf $assignment_path/.git
    echo
  done

cp ./clone_pep.sh $folderpath

# add readme
echo "# 5CCS2PEP - Practical Experiences of Programming
## Lecturers:
- Dr Andrew Coles (C++) (01 to 05)
- Dr Christian Urban (Scala) (06 to 10)

This repo contains all my completed coursework in the aforementioned module." > $folderpath/README.md

# git:init repo
git init $folderpath

# git:set environment variables
export GIT_DIR=$folderpath/.git
export GIT_WORK_TREE=$folderpath

# git:set credentials
git config user.name $name
git config user.email $email

# git:initial commit
git add -A
git commit -m 'Initial commit'

# git:create remote repo on github
curl \
  --silent \
  --user $username:$password \
  --request POST \
  --data '{
    "name": "'$foldername'",
    "description": "All completed exercises from KCL module 5CCS2PEP, year 2018/19.",
    "private": false,
    "has_issues": true,
    "has_projects": true,
    "has_wiki": true
  }' \
  https://api.github.com/user/repos > /dev/null

# git:push to remote repo
git push -u https://$username:$password@github.com/$username/$foldername master

# remove folder when done
rm -rf $cwd
info 'Removed temporary directory '$cwd

# final user message
info "Check out your final repo at https://github.com/$username/$foldername"
