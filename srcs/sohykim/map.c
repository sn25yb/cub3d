#include "../cub3d.h"

t_pair_int	make_dir(t_pair_int xy, int dir)
{
	t_pair_int	ret;
	const int	dr[5] = {0, -1, 1, 0, 0};
	const int	dc[5] = {0, 0, 0, -1, 1};

	ret = make_pair_int(xy.x + dc[dir], xy.y + dr[dir]);
	return (ret);
}

t_err   check_validmap(char **map, t_pair_dbl *pos)
{
    t_err   code;

	// 벽에 둘러쌓여있는가?
	// '1'과 'd', ' '가 아니면 좌우상하에 '1'이나 'd'가 존재해야한다.
    code = is_surrbywall(map);
    // printf("code1: %d\n", code);
	//개수가 맞게 존재하는가?
    if (!code)
        code = check_object(map);
    // printf("code2: %d\n", code);
    //player가 오브젝트에 도달가능한가?
	//player가 외부문에 도달가능한가?
    if (!code)
        code = check_player(map, pos);
    // printf("code3: %d\n", code);
    if (!code)
        code = check_door(map);
    // printf("code4: %d\n", code);
    if (!code)
        code = check_exit(map);
    // printf("code5: %d\n", code);
    return (code);
}

