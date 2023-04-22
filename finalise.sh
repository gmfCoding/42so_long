try_delete ()
{
	read -p "Doing you want to delete extraneous files? [y/N]" -r
	if [[ $REPLY =~ ^[Yy]$ ]]
	then
		echo -e "\033[1;31mDELETING:\033[0m"
		# exe rm -rf .vscode
		# exe rm -rf finalise.sh
	elif [[ ! $REPLY =~ ^[Nn]$ ]] && [[ ! -z $REPLY ]]
	then
		echo -e "\033[1;31mUnknown, try again!\033[0m"
		try_delete
	else
		echo -e "\033[1;32mCancelling!\033[0m"
	fi
}
exe() { echo -e "\033[1;32m$@\033[0m" ; "$@" ; }

if [[ "$@" =~ '-h' ]]
then
	(echo -e "By default finalise runs 'francinette --strict'. Use args to suppress defaults.\n\n-h help\n-f no francinette\n-s no --strict")
else
	echo -e "\033[4;1;36mPlease make sure that you have commited and pushed the files that will be neccessary!\033[0m"
	# make fclean
	echo -e "\033[1;32mgit ls-files\033[0m"
	echo -e "\033[1;33mVERIFY THAT YOUR REPOSITORY CONTAINS NO UNEXPECTED FILES!:\033[0m"
	git ls-files | paste - - - - - | column -t
	
	echo -e "\033[4;33mFINALISATIONS SCRIPT\033[0m"
	[[ ! "$@" =~ '-f' ]] && [[ "$@" =~ '-s' ]] && (exe francinette)
	[[ ! "$@" =~ '-f' ]] && [[ ! "$@" =~ '-s' ]] && (exe francinette --strict)

	if [[ "$@" =~ '-r' ]]
	then
		echo -e "\033[1;4;36mPlease make sure that you have commited and pushed the files that will be neccessary!\033[0m"
		try_delete
	fi
fi
