#ifndef ERRORS_UTILS_H
#define ERRORS_UTILS_H

#include <ErrorAPI.h>
#include <ParsedErrorAPI.h>

void ERR_initErrorApi();

PERR_Area ERR_liftArea(ERR_Area area);
PERR_Location ERR_liftLocation(ERR_Location location);
PERR_Subject ERR_liftSubject(ERR_Subject subject);
PERR_SubjectList ERR_liftSubjects(ERR_SubjectList subjects);
PERR_Feedback ERR_liftFeedback(ERR_Feedback feedback);

ERR_Area PERR_lowerArea(PERR_Area area);
ERR_Location PERR_lowerLocation(PERR_Location location);
ERR_Subject PERR_lowerSubject(PERR_Subject subject);
ERR_SubjectList PERR_lowerSubjects(PERR_SubjectList subjects);
ERR_Feedback PERR_lowerFeedback(PERR_Feedback feedback);
ERR_Summary PERR_lowerSummary(PERR_Summary pSummary);
#endif
