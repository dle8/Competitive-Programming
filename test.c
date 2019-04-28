void eval(char *cmdline)
 {
	char *argv[MAXARGS]; /* argv for execve() */
	int bg;
	pid_t pid;
	/* should the job run in bg or fg? */

	/* process id */
	bg = parseline(cmdline, argv);//returns 1 if background job is there
	if (argv[0] == NULL)	return;
	/* ignore empty lines */
	if (!builtin_cmd(argv)) {
		if ((pid = fork()) == 0) { //forking a child if not a built in command
			/* child runs user job */
			setpgid(0,0); //setting the process group id to 0
			if (execve(argv[0], argv, environ) < 0) { //returns -1 on error
			printf("%s: Command not found.\n", argv[0]);
			exit(0);
			}
			/* parent waits for foreground job to terminate */
		}
		if (!bg) {
			addjob(jobs,pid,FG,cmdline);//adding foreground jobs
			waitfg(pid); //waiting for all foregroung jobs to complete
		}
		else {
			addjob(jobs,pid,BG,cmdline);//adding background jobs
			printf("[%d] (%d) %s",pid2jid(pid),pid,cmdline);
		}
	}
	return;
}
