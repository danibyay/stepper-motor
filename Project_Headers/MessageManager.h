/*
 * MessageManager.h
 *
 *  Created on: Oct 29, 2016
 *      Author: Jesus
 */
#include"types.h"
#ifndef MESSAGEMANAGER_H_
#define MESSAGEMANAGER_H_
#define CARRIAGERETURN 13
#define MAX_RX_MSG_SIZE 26
#define BUFFER1 0
#define BUFFER2 1

void MsgManager_SendMessage(const u8 message[], u8 size);

void MsgManager_Init(void);

void MsgManager_ReceiveMessage(void);

bool MsgManager_TxisBusy(void);

void MsgManager_GetMessageReceived(char msg[]);

bool MsgManager_isNewMessageReady (void);

void MsgManager_clearMsg(u8 msg[]);

#endif /* MESSAGEMANAGER_H_ */
