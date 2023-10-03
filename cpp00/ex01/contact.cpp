#include <iostream>
#include "contact.hpp"
#include "utils.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact() {
	return ;
}

std::string Contact::get_fname() {
	return (this->fname);
}

std::string Contact::get_lname() {
	return (this->lname);
}

std::string Contact::get_nname() {
	return (this->nname);
}

std::string Contact::get_phone() {
	return (this->phone);
}

std::string Contact::get_secret() {
	return (this->secret);
}

void Contact::ShowContact(std::string num) {

	print_line("### Number ", num, "###");
	print_line("firstname	 : ", fname);
	print_line("lastname	 : ", lname);
	print_line("nickname 	 : ", nname);
	print_line("phone number : ", phone);
	print_line("dark secret  : ", secret);
	print_line();
}

void Contact::InsertContact() {
	this->fname = contact_prompt("firstname		: ");
	this->lname = contact_prompt("lastname		: ");
	this->nname = contact_prompt("nickname		: ");
	this->phone = contact_prompt("phone number	: ");
	this->secret = contact_prompt("dark secret	: ");
	print_line("New Contact save successly :)");
	print_line();
}

