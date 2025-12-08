#include <stdio.h>

int main(){
    char user[3], group[3], others[3];

    printf("User (rwx): "); scanf("%s", user);
    printf("Group (rwx): "); scanf("%s", group);
    printf("Others (rwx): "); scanf("%s", others);

    printf("Permissions: U=%s G=%s O=%s\n", user, group, others);
    return 0;
}

