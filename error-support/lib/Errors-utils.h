#ifndef ERRORS_UTILS_H
#define ERRORS_UTILS_H

#include <Errors.h>
#include <ParsedErrors.h>

PME_Area ME_liftArea(ME_Area area);
PME_Location ME_liftLocation(ME_Location location);
PME_Subject ME_liftSubject(ME_Subject subject);
PME_SubjectList ME_liftSubjects(ME_SubjectList subjects);
PME_Feedback ME_liftFeedback(ME_Feedback feedback);

#endif
