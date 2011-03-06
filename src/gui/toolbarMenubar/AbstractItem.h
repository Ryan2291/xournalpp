/*
 * Xournal++
 *
 * Abstract Toolbar / Menubar entry
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __ABSTRACTITEM_H__
#define __ABSTRACTITEM_H__

#include "../../control/Actions.h"
#include "../../util/String.h"

#include <gtk/gtk.h>

class AbstractItem: public ActionEnabledListener, public ActionSelectionListener {
public:
	AbstractItem(String id, ActionHandler * handler, ActionType action, GtkWidget * menuitem = NULL);
	virtual ~AbstractItem();

public:
	static void menuCallback(GtkMenuItem * menuitem, AbstractItem * toolItem);
	virtual void actionSelected(ActionGroup group, ActionType action);

	/**
	 * Override this method
	 */
	virtual void selected(ActionGroup group, ActionType action);

	virtual void actionEnabledAction(ActionType action, bool enabled);
	virtual void activated(GdkEvent * event, GtkMenuItem * menuitem, GtkToolButton * toolbutton);

	String getId();

	void setTmpDisabled(bool disabled);

protected:
	virtual void enable(bool enabled);

protected:
	ActionGroup group;
	ActionType action;

	String id;

	ActionHandler * handler;

	bool enabled;

private:
	gulong menuSignalHandler;
	GtkWidget * menuitem;
};

#endif /* __ABSTRACTITEM_H__ */
