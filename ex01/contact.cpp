#include <iostream>
#include "contact.hpp"
#include "utils.hpp"

contact::contact(void) {
	return ;
}

std::string contact::get_fname() {
	return (this->fname);
}

std::string contact::get_lname() {
	return (this->lname);
}

std::string contact::get_nname() {
	return (this->nname);
}

std::string contact::get_phone() {
	return (this->phone);
}

std::string contact::get_secret() {
	return (this->secret);
}

void contact::ShowContact() {
	print_line("firstname	 : ", fname);
	print_line("lastname	 : ", lname);
	print_line("nickname 	 : ", nname);
	print_line("phone number : ", phone);
	print_line("dark secret  : ", secret);
}

void contact::InsertContact() {
	fname = print_prompt("firstname		: ");
	lname = print_prompt("lastname		: ");
	nname = print_prompt("nickname		: ");
	phone = print_prompt("phone number	: ");
	secret = print_prompt("dark secret	: ");
}

