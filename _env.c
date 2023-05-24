#include "simple_shell.h"

/**
 * _settingenv - updates or adds an environment variable.
 * @variable_name:variable name.
 * @variable_value:variable value.
 * Return:0 - success, otherwise -1.
 */
int _settingenv(char *variable_name, char *variable_value)
{
	int i = 0;
	size_t name_len;
	char *var_new;

	name_len = _stringlen(variable_name);
	i = 0;
	/*updating an existing variable*/
	while (environ[i])
	{
		if (strncmp(environ[i], variable_name, name_len) == 0)
		{
			var_new = variable_build(variable_name, variable_value);
			/*Not sure but wanted to clear its mem b4 writing*/
			environ[i] = NULL;
			environ[i] = _stringdup(var_new);
			free(environ[i]);
			environ[i] = _stringdup(var_new);
			free(var_new);
			return (0);
		}
		i++;
	}
	/*adding a variable that never existed before*/
	var_new = variable_build(variable_name, variable_value);
	free(environ[i]);
	environ[i] = _stringdup(var_new);
	i++;
	environ[i] = NULL;
	var_new = NULL;

	return (0);
}
/**
 * variable_build - Builds an environment variable from its name and value.
 * @variable_name: Variable name.
 * @variable_value: Variable value.
 * Return: String containing full environment variable.
 */
char *variable_build(char *variable_name, char *variable_value)
{
	char *new_var;
	size_t var_len;

	var_len = _stringlen(variable_name) + _stringlen(variable_value) + 2;
	new_var = malloc(sizeof(char) * var_len);
	if (new_var == NULL)
	{
		perror("Error: Insufficient memory\n");
		return (NULL);
	}
	memset(new_var, 0, var_len);
	/*Data in the form: variable_name=variable_value*/
	new_var = _strcattings(new_var, variable_name);
	new_var = _strcattings(new_var, "=");
	new_var = _strcattings(new_var, variable_value);

	return (new_var);
}
/**
 * _unsettingenv - Removes an environment variable.
 * @variable_name: Variable name.
 * Return: 0 if successful -1,otherwise - -1.
 */
int _unsettingenv(char *variable_name)
{
	int i = 0;
	char **env_temp;
	size_t name_len;

	name_len = _stringlen(variable_name);
	while (environ[i])
	{
		if (strncmp(environ[i], variable_name, name_len) == 0)
		{
			env_temp = environ;
			free(env_temp[0]);
			do {
				env_temp[0] = env_temp[1];
				env_temp++;
			} while (*env_temp);
		}
		i++;
	}
	return (0);
}