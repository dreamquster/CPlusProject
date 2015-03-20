#include <mysql.h>
#include <my_global.h>

int main(int argc, char ** argv) {
    printf("MySQL client version:%s\n", mysql_get_client_info());
    MYSQL* mysql_con = mysql_init(NULL);

    mysql_real_connect(mysql_con, "10.4.32.131:3306", "tango_master", "nidaye", "test",
            0, NULL, 0);
    mysql_query(mysql_con, "select * from market_data_ks1 limit 1");
    MYSQL_RES* results = mysql_store_result(mysql_con);
    printf("%d", mysql_num_fields(results));

}
