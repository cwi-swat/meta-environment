#ifndef ERRORS_UTILS_H
#define ERRORS_UTILS_H

#include <ErrorAPI.h>
#include <ParsedErrorAPI.h>

void ERR_initFullErrorsApi();

PERR_Area ERR_liftArea(ERR_Area area);
PERR_Location ERR_liftLocation(ERR_Location location);
PERR_Subject ERR_liftSubject(ERR_Subject subject);
PERR_SubjectList ERR_liftSubjects(ERR_SubjectList subjects);
PERR_Feedback ERR_liftFeedback(ERR_Feedback feedback);

#endif
