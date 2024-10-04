#ifndef FT_ERR_H
# define FT_ERR_H

typedef enum e_err
{
	SUCCESS,
	MAP_FAILED, // 유효성 체크
	EXTRA // strerror / perror ()
}	t_err;

#endif
