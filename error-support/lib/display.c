#include "ErrorAPI.h"

void ERR_displayFeedback(ERR_Summary summary)
{
  char *feedbackType;
  ERR_FeedbackList feedbacks = ERR_getSummaryList(summary);
  char *producer = ERR_getSummaryProducer(summary);
  char *identification = ERR_getSummaryId(summary);

  while (!ERR_isFeedbackListEmpty(feedbacks)) {
    ERR_Feedback feedback = ERR_getFeedbackListHead(feedbacks);
    char *description = ERR_getFeedbackDescription(feedback);
    ERR_SubjectList subjects = ERR_getFeedbackList(feedback);

    if (ERR_isFeedbackInfo(feedback)) {
      feedbackType = "info";
    }
    else if (ERR_isFeedbackWarning(feedback)) {
      feedbackType = "warning";
    }
    else if (ERR_isFeedbackError(feedback)) {
      feedbackType = "error";
    }
    else if (ERR_isFeedbackFatalError(feedback)) {
      feedbackType = "fatal";
    }
    else {
      ATabort("unknown feedback type: %t\n", feedback);
      feedbackType = "";
    }

    while (!ERR_isSubjectListEmpty(subjects)) {
      ERR_Subject subject = ERR_getSubjectListHead(subjects);
      char *errorType = ERR_getSubjectDescription(subject);
      ERR_Location location = ERR_getSubjectLocation(subject);

      if (ERR_isLocationNoLocation(location)) {
        ATwarning("%s:%s: %s in %s: %s\n",
                  producer, 
                  feedbackType,
                  description, 
                  identification, 
                  errorType);
      }
      else {
        ERR_Area area = ERR_getLocationArea(location);
        char *filename = ERR_getLocationFilename(location);
        int line = ERR_getAreaBeginLine(area);
        int col = ERR_getAreaBeginColumn(area);

        ATwarning("%s:%s: %s in %s, line %d, col %d: %s\n",
                  producer, 
                  feedbackType,
                  description, 
                  filename, 
                  line, 
                  col, 
                  errorType);
      }
      subjects = ERR_getSubjectListTail(subjects);
    }

    feedbacks = ERR_getFeedbackListTail(feedbacks);
  }
}
