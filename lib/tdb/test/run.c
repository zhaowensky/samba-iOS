#include "../common/tdb_private.h"
#include "../common/io.c"
#include "../common/tdb.c"
#include "../common/lock.c"
#include "../common/freelist.c"
#include "../common/traverse.c"
#include "../common/transaction.c"
#include "../common/error.c"
#include "../common/open.c"
#include "../common/check.c"
#include "../common/hash.c"
#include "tap-interface.h"
#include <stdlib.h>
#include "logging.h"

int main(int argc, char *argv[])
{
	struct tdb_context *tdb;
	TDB_DATA key, data;

	plan_tests(10);
	tdb = tdb_open_ex("run.tdb", 1024, TDB_CLEAR_IF_FIRST,
			  O_CREAT|O_TRUNC|O_RDWR, 0600, &taplogctx, NULL);

	ok1(tdb);
	key.dsize = strlen("hi");
	key.dptr = (void *)"hi";
	data.dsize = strlen("world");
	data.dptr = (void *)"world";

	ok1(tdb_store(tdb, key, data, TDB_MODIFY) < 0);
	ok1(tdb_error(tdb) == TDB_ERR_NOEXIST);
	ok1(tdb_store(tdb, key, data, TDB_INSERT) == 0);
	ok1(tdb_store(tdb, key, data, TDB_INSERT) < 0);
	ok1(tdb_error(tdb) == TDB_ERR_EXISTS);
	ok1(tdb_store(tdb, key, data, TDB_MODIFY) == 0);

	data = tdb_fetch(tdb, key);
	ok1(data.dsize == strlen("world"));
	ok1(memcmp(data.dptr, "world", strlen("world")) == 0);
	free(data.dptr);

	key.dsize++;
	data = tdb_fetch(tdb, key);
	ok1(data.dptr == NULL);
	tdb_close(tdb);

	return exit_status();
}
