Action()
{
	//
//	
	web_reg_save_param_ex("paramname=uSession","LB=Session\" value=\"","RB=\"/>",SEARCH_FILTERS,"scope=Body","requestURL=*nav.pl?*",LAST);
	web_url("webtours",
	        "URL=http://127.0.0.1:1080/webtours/",
	        "TargetFrame=",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=",
	        "Snapshot=t1.inf",
	        "Mode=HTML",
	        LAST);

	/* Login */

	lr_think_time(21);

	web_submit_data("login.pl",
	                "Action=http://127.0.0.1:1080/cgi-bin/login.pl",
	                "Method=POST",
	                "TargetFrame=body",
	                "RecContentType=text/html",
	                "Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
	                "Snapshot=t2.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=userSession", "Value={uSession}", ENDITEM,
	                "Name=username", "Value=jojo", ENDITEM,
	                "Name=password", "Value=bean", ENDITEM,
	                "Name=JSFormSubmit", "Value=off", ENDITEM,
	                "Name=login.x", "Value=48", ENDITEM,
	                "Name=login.y", "Value=8", ENDITEM,
	                LAST);

	/* Click on Flights */

	lr_think_time(14);
	
	
//	web_reg_save_param_ex("paramname=pickUP","LB=value=\"","RB=</option>","savelen=2","saveoffset=3","ordinal=all",LAST);
	web_reg_save_param_ex("paramname=pickUP","LB=value=\"","RB=</option>","ordinal=all",LAST);
	web_reg_save_param_ex("paramname=seatType","LB=seatType\" value=\"","RB=\" />","ordinal=all",LAST); 
	web_reg_save_param_ex("paramname=seatPre","LB=\"seatPref\" value=\"","RB=\" />","ordinal=all",LAST); 
	web_url("Search Flights Button",
	        "URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search",
	        "TargetFrame=body",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home",
	        "Snapshot=t3.inf",
	        "Mode=HTML",
	        LAST);

	/* Find Flight */

	lr_think_time(42);
	
	//"savelen=5"
//	web_reg_save_param_ex("paramname=flightNumber","LB=name=\"outboundFlight\" value=\"","RB=\">",LAST);	
	//web_reg_save_param_ex("paramname=flightCost","LB=","RB=</TD>",LAST);	
	web_reg_save_param_ex("paramname=flightCost","LB=center\">","RB=</TD>","savelen=-1",LAST);
	web_submit_data("reservations.pl",
	                "Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
	                "Method=POST",
	                "TargetFrame=",
	                "RecContentType=text/html",
	                "Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome",
	                "Snapshot=t4.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=advanceDiscount", "Value=0", ENDITEM,
	                "Name=depart", "Value={pickUP_5}", ENDITEM,
	                "Name=departDate", "Value=08/01/2021", ENDITEM,
	                "Name=arrive", "Value={pickUP_3}", ENDITEM,
	                "Name=returnDate", "Value=08/02/2021", ENDITEM,
	                "Name=numPassengers", "Value=1", ENDITEM,
	                "Name=seatPref", "Value={seatPre_2}", ENDITEM,
	                "Name=seatType", "Value={seatType_2}", ENDITEM,
	                "Name=.cgifields", "Value=roundtrip", ENDITEM,
	                "Name=.cgifields", "Value=seatType", ENDITEM,
	                "Name=.cgifields", "Value=seatPref", ENDITEM,
	                "Name=findFlights.x", "Value=56", ENDITEM,
	                "Name=findFlights.y", "Value=6", ENDITEM,
	                LAST);

	/* Select Flight */

	lr_think_time(75);

	web_submit_data("reservations.pl_2",
	                "Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
	                "Method=POST",
	                "TargetFrame=",
	                "RecContentType=text/html",
	                "Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl",
	                "Snapshot=t5.inf",
	                "Mode=HTML",
	                ITEMDATA,
	               // "Name=outboundFlight", "Value=esfew4336345", ENDITEM, -> Not Found line
	                "Name=outboundFlight", "Value=flightCost_3", ENDITEM,
	                "Name=numPassengers", "Value=1", ENDITEM,
	                "Name=advanceDiscount", "Value=0", ENDITEM,
	                "Name=seatType", "Value=First", ENDITEM,
	                "Name=seatPref", "Value=Aisle", ENDITEM,
	                "Name=reserveFlights.x", "Value=38", ENDITEM,
	                "Name=reserveFlights.y", "Value=9", ENDITEM,
	                LAST);

	/* Payment Details */

	lr_think_time(34);

	web_submit_data("reservations.pl_3",
	                "Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
	                "Method=POST",
	                "TargetFrame=",
	                "RecContentType=text/html",
	                "Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl",
	                "Snapshot=t6.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=firstName", "Value=Jojo", ENDITEM,
	                "Name=lastName", "Value=Bean", ENDITEM,
	                "Name=address1", "Value=sfsdg", ENDITEM,
	                "Name=address2", "Value=534352", ENDITEM,
	                "Name=pass1", "Value=Jojo Bean", ENDITEM,
	                "Name=creditCard", "Value=534675568", ENDITEM,
	                "Name=expDate", "Value=2025", ENDITEM,
	                "Name=saveCC", "Value=on", ENDITEM,
	                "Name=oldCCOption", "Value=", ENDITEM,
	                "Name=numPassengers", "Value=1", ENDITEM,
	                "Name=seatType", "Value=First", ENDITEM,
	                "Name=seatPref", "Value=Aisle", ENDITEM,
	                "Name=outboundFlight", "Value=040;657;08/01/2021", ENDITEM,
	                "Name=advanceDiscount", "Value=0", ENDITEM,
	                "Name=returnFlight", "Value=", ENDITEM,
	                "Name=JSFormSubmit", "Value=off", ENDITEM,
	                "Name=.cgifields", "Value=saveCC", ENDITEM,
	                "Name=buyFlights.x", "Value=48", ENDITEM,
	                "Name=buyFlights.y", "Value=7", ENDITEM,
	                LAST);

	lr_think_time(9);

	web_url("SignOff Button",
	        "URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1",
	        "TargetFrame=body",
	        "Resource=0",
	        "RecContentType=text/html",
	        "Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights",
	        "Snapshot=t7.inf",
	        "Mode=HTML",
	        LAST);

	return 0;
}