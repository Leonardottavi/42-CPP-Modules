/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:41:52 by lottavi           #+#    #+#             */
/*   Updated: 2025/05/02 14:41:52 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data *ds = new Data;
    ds->a = 42;
    ds->b = 3.14;

    cout << "----------------------------" << endl;
    cout << "Before: " << ds << endl;
    uintptr_t rawPtr = Serializer::serialize(ds);
    cout << "After: " << rawPtr << endl;
    cout << "----------------------------" << endl;

    Data *tmp = NULL;
    tmp = Serializer::deserialize(rawPtr);
    cout << "Before: " << tmp << endl;
    cout << "tmp->a: " << tmp->a << endl;
    cout << "tmp->b: " << tmp->b << endl;
    cout << "----------------------------" << endl;

    delete ds;
    return 0;
}
