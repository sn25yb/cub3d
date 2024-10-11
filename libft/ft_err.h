#ifndef FT_ERR_H
# define FT_ERR_H
# define MSG_MAP_FAILED "INVALID MAP FILE"
# define MSG_ARG_FAILED "INVALID ARGUMENTS"

typedef enum e_err
{
	ARG_FAILED = 2,
	MAP_FAILED, // 유효성 체크
	IMG_FAILED,
	EXTRA // strerror / perror ()
}	t_err;

#endif
