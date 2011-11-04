program full;
const	NumberOfDaysInYear	=	365;
type	Days			=	( monday, tuesday, wenesday, thursday, friday, saturday, sunday );
	WorkDays		=	monday .. friday;
	WeekEnd			=	saturday .. sunday;
	Month			=	( january, february, march, april, may, june, july, august, september, october, november, december );
	Date			=	record
						theyear : integer;
						themonth : Month;
						theday : integer
					end;
	Date2			=	Date;
	Appointment		=	record
						thetitle : string;
						thedate : Date;
						thelocation : string
					end;
	AppointmentList		=	record
						theappointment : Appointment;
						thenext : ^AppointmentList
					end;
	AppointmentListPtr	=	^AppointmentList;
	Calendar		=	array [ january .. december, 1 .. 31 ] of AppointmentList;
var	MyCalendar		:	Calendar;
	today			:	Date2;
(*
 * adding an appointment to a calendar
 *)
procedure addAppointmentTo ( rdv : Appointment; var cal : Calendar );
var ptr : ^AppointmentList;
function createAppointmentListPtr : AppointmentListPtr;
begin
end;
begin
	ptr := createAppointmentListPtr();
	Ptr^.thenext := cal [ rdv.thedate.themonth, rdv.thedate.theday ];
	pTr^.theappointment := rdv;
	cal [ rdv.thedate.themonth, rdv.thedate.theday ] := ptR
end;
(*
 * count number of appointment for a specific date in a calendar
 *)
function appointmentCountForDate ( thedate : Date; cal : Calendar ) : integer;
var	current	: AppointmentListPtr;
	res	: integer;
begin
	res := 0;
	current := cal [ rdv.thedate.themonth, rdv.thedate.theday ];
	while ( current <> NIL ) do begin
		res := res + 1;
		current := current^.thenext
	end;
	appointmentCountForDate := res
end;
begin
end.
