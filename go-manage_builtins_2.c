#include "shell.h"

/**
 * handle_exittings - exits the shell
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */

int handle_exittings(info_s *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = err_numbers(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			printtings_error(info, "Illegal number: ");
			puttings_err(info->argv[1]);
			putttingchar_err('\n');
			return (1);
		}
		info->error_code = err_numbers(info->argv[1]);
		return (-2);
	}
	info->error_code = -1;
	return (-2);
}
/**
 * handlings_cd - changes the current directory of the process
 * @info: contains simulated arguments for a function pointer,
 *		  allowing for a consistent function prototype
 *
 * Return: 0
 */

int handlings_cd(info_s *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puttings("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _gettingenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _gettingenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_stringcmp(info->argv[1], "-") == 0)
	{
		if (!_gettingenv(info, "OLDPWD="))
		{
			_puttings(s);
			_puttingchar('\n');
			return (1);
		}
		_puttings(_gettingenv(info, "OLDPWD=")), _puttingchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _gettingenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);

	if (chdir_ret == -1)
	{
		printtings_error(info, "can't cd to ");
		puttings_err(info->argv[1]), putttingchar_err('\n');
	}
	else
	{
		_settingsenv(info, "OLDPWD", _gettingenv(info, "PWD="));
		_settingsenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * handle_helppings - prints a message for aa function not implemented
 * @info:	contains simulated arguments for a function pointer,
 *			constant function prototype.
 * Return: 0
 */

int handle_helppings(info_s *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puttings("help call works. Function not yet implemented \n");
	if (0)
		_puttings(*arg_array);

	return (0);
}

/**
 * handle_history - displays the history list, one command by line, preceded
 *					with line numbers, starting at 0.
 * @info: contains simulated arguments for a function pointer,
 *		  constant function prototype.
 *	Return: Always 0
 */

int handle_history(info_s *info)
{
	print_listtings(info->history);

	return (0);
}
