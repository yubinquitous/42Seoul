/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubin <yubchoi@student.42>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:37:36 by yubchoi           #+#    #+#             */
/*   Updated: 2022/06/25 00:47:05 by yubin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int select_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void compare_up_down(t_command_cnt c, t_sort *temp)
{
	if (c.uu < c.ud && c.uu < c.du && c.uu < c.dd)
	{
		temp->command_min = c.uu;
		temp->flag = UU;
	}
	else if (c.ud < c.uu && c.ud < c.du && c.ud < c.dd)
	{
		temp->command_min = c.ud;
		temp->flag = UD;
	}
	else if (c.du < c.uu && c.du < c.ud && c.du < c.dd)
	{
		temp->command_min = c.du;
		temp->flag = DU;
	}
	else
	{
		temp->command_min = c.dd;
		temp->flag = DD;
	}
}

int count_up(t_stack s, int idx)
{
	int length;

	length = (s.size + idx - s.head) % s.size;
	return (length);
}

int count_down(t_stack s, int idx)
{
	int length;

	length = stack_size(s, s.size) - count_up(s, idx);
	return (length);
}

void count_command(t_dual_stack *ds, t_sort *temp)
{
	t_command_cnt command_cnt;

	command_cnt.uu = select_bigger(
		count_up(ds->a, temp->a_idx), count_up(ds->b, temp->b_idx));
	command_cnt.ud = count_up(ds->a, temp->a_idx) + count_down(ds->b, temp->b_idx);
	command_cnt.du = count_down(ds->a, temp->a_idx) + count_up(ds->b, temp->b_idx);
	command_cnt.dd = select_bigger(
		count_down(ds->a, temp->a_idx), count_down(ds->b, temp->b_idx));
	compare_up_down(command_cnt, temp);
}
