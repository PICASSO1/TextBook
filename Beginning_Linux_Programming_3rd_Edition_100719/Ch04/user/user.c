#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <string.h>

int 
main()
{
	uid_t uid = getuid();
	gid_t gid = getgid();

	struct passwd *pw = (struct passwd *)NULL;

	printf("User is : %s \n", getlogin());
	printf("User IDs: UID = %d; GID = %d \n", uid, gid);

	pw = getpwuid(uid);
	printf("UID /etc/passwd entry: ");
	printf("\n\
		Username: %s \
		Password: %s \
		UID: %d \
		GID: %d \
		Real Name: %s \
		Home: %s \
		Shell: %s \n", pw->pw_name, pw->pw_passwd, pw->pw_uid, pw->pw_gid, pw->pw_gecos, pw->pw_dir, pw->pw_shell);

	pw = getpwnam("picasso");
	printf("\"picasso\" /etc/passwd entry: ");
	printf("\n\
		Username: %s \
		Password: %s \
		UID: %d \
		GID: %d \
		Real Name: %s \
		Home: %s \
		Shell: %s \n", pw->pw_name, pw->pw_passwd, pw->pw_uid, pw->pw_gid, pw->pw_gecos, pw->pw_dir, pw->pw_shell);

	return 0;
}
/*
Note: struct passwd difined in: / usr / include / pwd.h

struct passwd {
	char *pw_name;		// Username.
	char *pw_passwd;		// Password.
	__uid_t pw_uid;		// User ID.
	__gid_t pw_gid;		// Group ID.
	char *pw_gecos;		// Real name.
	char *pw_dir;			// Home directory.
	char *pw_shell;		// Shell program.
};
*/